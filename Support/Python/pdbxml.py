import xml.etree.ElementTree as et
#====================================================================#
def maybe_space(s):
    return ' ' + s if s else ''

class CType(object):

    def unwrap_to(self, visitor):
        t = self
        while isinstance(t, CWrap):
            t.accept(visitor)
            visitor.after_visit(t)
            t = t.next
        return t

    def _decorate(self, s):
        decorator = Decorator(s)
        core = self.unwrap_to(decorator)
        return core, decorator.result
    
    def define(self, var, indent, tab):
        core, s1 = self._decorate(var)
        s2 = indent + core.part_def(indent, tab)
        return s2 + maybe_space(s1) + ';\n'

    @staticmethod
    def get_prefix(t):
        assert isinstance(t, CPrefix)
        return t.prefix
    
    @staticmethod
    def extract_prefix(t):
        if isinstance(t, CAttrTerm):
            return t.attr_str + ' ' + CType.get_prefix(t.core_type)
        else:
            return CType.get_prefix(t)

    @property
    def sig(self):
        core, s1 = self._decorate('')
        s2 = CType.extract_prefix(core)
        return s2 + maybe_space(s1)

    def _search_dep(self, dep):
        searcher = DepSearcher(dep)
        t = self.unwrap_to(searcher)
        core = t.core_type if isinstance(t, CAttrTerm) else t
        if isinstance(core, CTypeRef):
            dep.add(core.name)
        return core, searcher.has_ptr
    
    def search_depending_and_using(self, dep, use):
        t, has_ptr = self._search_dep(dep)
        if isinstance(t, CTypeRef) and not has_ptr:
            use.add(t.name)
        elif isinstance(t, CTree):
            t.search_depending_and_using(dep, use)

    def search_depending(self, dep):
        t, _ = self._search_dep(dep)
        assert isinstance(t, CPrefix)

class CTerm(CType):
    # (abstract) part_def
    pass

class CPrefix(CTerm):
    # (abstract property) prefix
    def part_def(self, indent, tab):
        return self.prefix

class CPrim(CPrefix):
    def __init__(self, name):
        self.name = name

    # (impl)
    @property
    def prefix(self):
        return self.name

class CTypeRef(CPrefix):
    def __init__(self, name):
        self.name = name

    # (impl)
    @property
    def prefix(self):
        return self.name

class CBrace(CTerm):
    # (abstract property) keyword
    # (abstract) child_def(indent, tab)
    def qualified_name(self, inner_name):
        return self.keyword + maybe_space(inner_name)
    
    def def_body(self, indent, tab):
        s = ''
        s += indent + '{' + '\n'
        s += self.child_def(indent + tab, tab)
        s += indent + '}'
        return s
    
    # (impl)
    def part_def(self, indent, tab):
        return self.keyword + '\n' + self.def_body(indent, tab)

class CEnumEntry:
    def __init__(self, name, val):
        self.name = name
        self.val = val

class CEnum(CBrace):
    def __init__(self):
        self.__entries = []
    
    def add(self, name, val):
        self.__entries.append(CEnumEntry(name, val))
    
    @property
    def entries(self):
        return self.__entries
    
    # (impl)
    @property
    def keyword(self):
        return 'enum'
    
    # (impl)
    def child_def(self, indent, tab):
        if not self.__entries:
            return ''
        
        s = ''
        last = self.__entries[-1]
        for e in self.__entries:
            s += indent + e.name + ' = ' + str(e.val)
            if e is not last:
                s += ','
            s += '\n'
        return s

class CTreeEntry:
    def __init__(self, type, name, offset):
        self.type = type
        self.name = name
        self.offset = offset

class CTree(CBrace):
    def __init__(self):
        self.__entries = []
    
    def add(self, type, name, offset = 0):
        self.__entries.append(CTreeEntry(type, name, offset))
    
    @property
    def members(self):
        return self.__entries
    
    # (impl)
    def child_def(self, indent, tab):
        s = ''
        for e in self.__entries:
            s += e.type.define(e.name, indent, tab)
        return s

    def search_depending_and_using(self, dep, use):
        for e in self.__entries:
            e.type.search_depending_and_using(dep, use)

    def get_dep(self):
        dep = set()
        use = set()
        self.search_depending_and_using(dep, use)
        return (dep, use)

class CStruct(CTree):
    # (impl)
    @property
    def keyword(self):
        return 'struct'

class CUnion(CTree):
    # (impl)
    @property
    def keyword(self):
        return 'union'


class TypeAttr(object):
    def __init__(self, name, num):
        self.__name = name
        self.__num = num
    
    def __cmp__(self, other):
        return cmp(self.__num, other.__num)
    
    @property
    def name(self):
        return self.__name

class TypeAttrs(object):
    unaligned = TypeAttr('__unaligned', -3)
    const     = TypeAttr('const', -2)
    volatile  = TypeAttr('volatile', -1)

    __map = {}
    for attr in [unaligned, const, volatile]:
        __map[attr.name] = attr

    @classmethod
    def lookup(cls, s):
        return cls.__map[s]

class CAttrTerm(CTerm):
    def __init__(self, type, attrs):
        self.__type = type
        self.__attrs = attrs
    
    @property
    def core_type(self):
        return self.__type
    
    @property
    def attr_str(self):
        return ' '.join(map(lambda attr: attr.name, sorted(self.__attrs)))

    # (impl)
    def part_def(self, indent, tab):
        return self.attr_str + ' ' + self.__type.part_def(indent, tab)

########################################
class CWrap(CType):
    pass

class CPtr(CWrap):
    def __init__(self, next):
        self.next = next

    def accept(self, visitor):
        visitor.visit_ptr(self)

class CArr(CWrap):
    def __init__(self, next, len):
        self.next = next
        self.len = len

    def accept(self, visitor):
        visitor.visit_arr(self)

class CallConv(object):
    def __init__(self, keyword):
        self.keyword = keyword

class CallConvs(object):
    default = CallConv(None)
    stdcall = CallConv('__stdcall')
    cdecl = CallConv('__cdecl')

class CFunc(CWrap):
    def __init__(self, ret_type, call_conv = CallConvs.default):
        self.next = ret_type
        self.args = []
        self.call_conv = call_conv
    
    @property
    def ret_type(self):
        return self.next
        
    def add(self, type):
        self.args.append(type)
        
    def accept(self, visitor):
        visitor.visit_func(self)
        
class CBits(CWrap):
    def __init__(self, base_type, len):
        self.next = base_type
        self.len = len

    def accept(self, visitor):
        visitor.visit_bits(self)

class WrapVisitor(object):
    
    def after_visit(self, t):
        pass
    
    def visit_arr(self, t):
        pass
    
    def visit_ptr(self, t):
        pass
    
    def visit_func(self, t):
        pass
    
    def visit_bits(self, t):
        pass

class Decorator(WrapVisitor):

    def __init__(self, s):
        self._s = s
        self._last_is_ptr = False

    def after_visit(self, t):
        self._last_is_ptr = isinstance(t, CPtr)

    def _maybe_paren(self, s):
        return '(' + s + ')' if self._last_is_ptr else s

    def visit_arr(self, t):
        self._s = self._maybe_paren(self._s) + '[' + str(t.len) + ']'

    def visit_ptr(self, t):
        self._s = '*' + self._s

    @staticmethod
    def _func_args_str(func):
        if not func.args:
            return 'void'
        else:
            return ', '.join(map(lambda t: t.sig, func.args))

    @staticmethod
    def _with_call_conv(s, conv):
        if conv is CallConvs.default:
            return s
        else:
            return conv.keyword + ' ' + s
        
    def visit_func(self, t):
        self._s = (
            self._maybe_paren(Decorator._with_call_conv(self._s, t.call_conv)) +
            '(' + Decorator._func_args_str(t) + ')')

    def visit_bits(self, t):
        self._s += ' : ' + str(t.len);
    
    @property
    def result(self):
        return self._s

class DepSearcher(WrapVisitor):

    def __init__(self, dep_set):
        self.has_ptr = False
        self._dep_set = dep_set

    def visit_ptr(self, t):
        self.has_ptr = True

    def visit_func(self, t):
        for arg in t.args:
            arg.search_depending(self._dep_set)
    
########################################        
class PrimTypes(object):
    VOID        = CPrim('void')
    WCHAR       = CPrim('wchar_t')
    
    CHAR        = CPrim('char')
    INT         = CPrim('int')
    SHORT       = CPrim('short')
    LONG        = CPrim('long')
    LONGLONG    = CPrim('__int64')
    
    UCHAR       = CPrim('unsigned char')
    UINT        = CPrim('unsigned int')
    USHORT      = CPrim('unsigned short')
    ULONG       = CPrim('unsigned long')
    ULONGLONG   = CPrim('unsigned __int64')

    FLOAT       = CPrim('float')
    DOUBLE      = CPrim('double')

#====================================================================#
class Locator(object):
    def __init__(self, elem):
        self._elem = elem
        self._index = -1

    def find(self, id):
        self._index += 1
        child = self._elem[self._index]
        # assert int(child.attrib['id']) == id
        # BELOW: for TEST purposes
        if int(child.attrib['id']) != id:
            print "warn: need id %d but current id is %s" % (id, child.attrib['id'])
            return self._elem.findall(".//*[@id='%s']" % id)[0]
        return child

class XmlParser(object):
    def __init__(self, path):
        tree = et.parse(path)
        root = tree.getroot()
        self.root = root
        self._locFunc = Locator(root[0])
        self._locUnnamed = Locator(root[1])
        self._named = root[2]
    
    def _read_named(self, e_type):
        return self._read_group(e_type)

    def _read_unnamed(self, id):
        e_unnamed = self._locUnnamed.find(id)
        return self._read_group(e_unnamed)

    def _read_group(self, e_type):
        if e_type.tag == 'enum':
            return self._read_enum(e_type)
        else:
            tree = CStruct() if e_type.tag == 'struct' else CUnion()
            return self._read_tree(e_type, tree)

    def _read_tree(self, e_type, t):
        for e_field in e_type:
            name = e_field.attrib['name']
            # TODO? offset
            # TODO? merge into _read_field()
            typ = self._read_field(e_field)
            t.add(typ, name)
        return t

    def _read_enum(self, e_type):
        t = CEnum()
        for e_const in e_type:
            name = e_const.attrib['name']
            val = e_const.attrib['val']
            t.add(name, val)
        return t
    
    def _read_field(self, e_field):
        if e_field.tag == 'bit-field':
            t = self._read_type(e_field, False)
            t = CBits(t, int(e_field.attrib['len']))
        else:
            t = self._read_type(e_field, True)
        return t
    
    def _read_type(self, e_field, hasWrap):
        attrs = e_field.attrib
        t = self._read_base(attrs['base'])
        if attrs.has_key('attr'):
            t = CAttrTerm(t, self._read_attr(attrs['attr']))
        if hasWrap:
            t = self._read_wrap(attrs['wrap'], t)
        return t
    
    def _read_attr(self, attr):
        attrSet = set()
        for s in attr.split():
            attrSet.add(TypeAttrs.lookup(s))
        return attrSet
    
    def _read_base(self, base):
        sigil = base[0]
        name = base[1:]
        if sigil == '.':
            return self._read_prim(name)
        elif sigil == '$':
            return self._read_typeRef(name)
        else:
            return self._read_unnamed(int(name))
    
    # TODO define this as a class var
    __primTypes = {
        'VOID':         PrimTypes.VOID,
        'WCHAR':        PrimTypes.WCHAR,
        
        'CHAR':         PrimTypes.CHAR,
        'UCHAR':        PrimTypes.UCHAR,
        'SHORT':        PrimTypes.SHORT,
        'USHORT':       PrimTypes.USHORT,
        'INT':          PrimTypes.INT,
        'UINT':         PrimTypes.UINT,
        'LONG':         PrimTypes.LONG,
        'ULONG':        PrimTypes.ULONG,
        
        'LONGLONG':     PrimTypes.LONGLONG,
        'ULONGLONG':    PrimTypes.ULONGLONG,
        
        'FLOAT':        PrimTypes.FLOAT,
        'DOUBLE':       PrimTypes.DOUBLE,
    }
    
    def _read_prim(self, name):
        return XmlParser.__primTypes[name]
    
    def _read_typeRef(self, name):
        return CTypeRef(name)
    
    def _read_wrap(self, wrap, t):
        arr = wrap.split()
        i = 0
        while i < len(arr):
            c = arr[i]
            if c == 'a':
                t = CArr(t, int(arr[i + 1]))
                i += 2
            elif c == 'p':
                t = CPtr(t)
                i += 1
            else:
                conv = CallConvs.stdcall if c == 'F' else CallConvs.default
                t = self._read_func(int(arr[i + 1]), t, conv)
                i += 2
        return t

    def _read_func(self, id, t, conv):
        e_func = self._locFunc.find(id)
        t = CFunc(t, conv)
        for e_arg in e_func:
            t.add(self._read_type(e_arg, True))
        return t

    def read_to_storage(self, storage):
        for e_type in self._named:
            name = e_type.attrib['name']
            type = self._read_named(e_type)
            storage.add(name, type)

class ImplItem(object):

    def __init__(self, type, file, index):
        self.type = type
        self.file = file
        self.index = index
    
class Storage(object):

    def __init__(self):
        self._data = {}

    def begin_file(self, file):
        self._file = file
        self._indices = {}

    def end_file(self):
        self._file = None
        self._indices = None

    def _fetch_index(self, name):
        index = self._indices.get(name)
        index = index + 1 if (index is not None) else 0
        self._indices[name] = index
        return index

    def add(self, name, type):
        file = self._file
        index = self._fetch_index(name)
        items = self._data.get(name)
        if not items:
            items = []
            self._data[name] = items
        items.append(ImplItem(type, file, index))

    @property
    def impls(self):
        return self._data

#====================================================================#
parser = XmlParser('f:\\zzz.xml')
st = Storage()
st.begin_file(1)
parser.read_to_storage(st)
st.end_file()
