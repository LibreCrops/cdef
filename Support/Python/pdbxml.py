import xml.etree.ElementTree as et
#====================================================================#
def maybeSpace(s):
    return ' ' + s if s else ''

class CType(object):
    def wrap(self, var):
        s = var
        t = self
        while isinstance(t, CWrap):
            s = t.decorate(s)
            t = t.next
        return s, t
    
    def define(self, var, indent, tab):
        s1, core = self.wrap(var)
        s2 = indent + core.partDef(indent, tab)
        return s2 + maybeSpace(s1) + ';\n'

    @staticmethod
    def getPrefix(t):
        assert isinstance(t, CPrefix)
        return t.prefix
    
    @staticmethod
    def extractPrefix(t):
        if isinstance(t, CAttrTerm):
            return t.attrStr + ' ' + CType.getPrefix(t.coreType)
        else:
            return CType.getPrefix(t)

    @property
    def sig(self):
        s1, core = self.wrap('')
        s2 = CType.extractPrefix(core)
        return s2 + maybeSpace(s1)

class CTerm(CType):
    # (abstract) partDef
    pass

class CPrefix(CTerm):
    # (abstract property) prefix
    def partDef(self, indent, tab):
        return self.prefix

class CPrim(CPrefix):
    def __init__(self, name):
        self.__name = name

    # (impl)
    @property
    def prefix(self):
        return self.__name

class CTypeRef(CPrefix):
    def __init__(self, name):
        self.__name = name

    # (impl)
    @property
    def prefix(self):
        return self.__name

class CBrace(CTerm):
    # (abstract property) keyword
    # (abstract) childDef(indent, tab)
    def qualifiedName(self, innerName):
        return self.keyword + maybeSpace(innerName)
    
    def defBody(self, indent, tab):
        s = ''
        s += indent + '{' + '\n'
        s += self.childDef(indent + tab, tab)
        s += indent + '}'
        return s
    
    # (impl)
    def partDef(self, indent, tab):
        return self.keyword + '\n' + self.defBody(indent, tab)

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
    def childDef(self, indent, tab):
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
    def childDef(self, indent, tab):
        s = ''
        for e in self.__entries:
            s += e.type.define(e.name, indent, tab)
        return s

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

class CWrap(CType):
    # (abstract) decorate(s)
    pass

class CPtr(CWrap):
    def __init__(self, next):
        self.next = next

    # (impl)
    def decorate(self, s):
        if isinstance(self.next, CArr) or isinstance(self.next, CFunc):
            return '(*' + s + ')'
        else:
            return '*' + s

class CArr(CWrap):
    def __init__(self, next, len):
        self.next = next
        self.len = len
    
    # (impl)
    def decorate(self, s):
        return s + '[' + str(self.len) + ']'

class CFunc(CWrap):
    def __init__(self, retType):
        self.next = retType
        self.args = []
    
    @property
    def retType(self):
        return self.next
        
    def add(self, type):
        self.args.append(type)
    
    def decorate(self, s):
        return s + '(' + ', '.join(map(lambda arg: arg.sig, self.args)) + ')'

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
    def coreType(self):
        return self.__type
    
    @property
    def attrStr(self):
        return ' '.join(map(lambda attr: attr.name, sorted(self.__attrs)))

    # (impl)
    def partDef(self, indent, tab):
        return self.attrStr + ' ' + self.__type.partDef(indent, tab)

class CBits(CWrap):
    def __init__(self, baseType, len):
        self.next = baseType
        self.len = len
    
    # (impl)
    def decorate(self, s):
        return s + ' : ' + str(self.len)

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
        self.__elem = elem
        self.__index = -1

    def find(self, id):
        self.__index += 1
        child = self.__elem[self.__index]
        print 'cur id = ', child.attrib['id']
        print 'expected id =', id
        assert int(child.attrib['id']) == id
        return child

class XmlParser(object):
    def __init__(self, path):
        tree = et.parse(path)
        root = tree.getroot()
        self.root = root
        self.__locFunc = Locator(root[0])
        self.__locUnnamed = Locator(root[1])
        
    def readNamed(self, eType):
        return self.readGroup(eType)

    def readUnnamed(self, id):
        eUnnamed = self.__locUnnamed.find(id)
        return self.readGroup(eUnnamed)

    def readGroup(self, eType):
        if eType.tag == 'enum':
            return self.readEnum(eType)
        else:
            tree = CStruct() if eType.tag == 'struct' else CUnion()
            return self.readTree(eType, tree)

    def readTree(self, eType, t):
        for eField in eType:
            name = eField.attrib['name']
            # TODO? offset
            # TODO? merge into readField()
            typ = self.readField(eField)
            t.add(typ, name)
        return t

    def readEnum(self, eType):
        t = CEnum()
        for eConst in eType:
            name = eConst.attrib['name']
            val = eConst.attrib['val']
            t.add(name, val)
        return t
    
    def readField(self, eField):
        if eField.tag == 'bit-field':
            t = self.readType(eField, False)
            t = CBits(t, int(eField.attrib['len']))
        else:
            t = self.readType(eField, True)
        return t
    
    def readType(self, eField, hasWrap):
        attrs = eField.attrib
        t = self.readBase(attrs['base'])
        if attrs.has_key('attr'):
            t = CAttrTerm(t, self.readAttr(attrs['attr']))
        if hasWrap:
            t = self.readWrap(attrs['wrap'], t)
        return t
    
    def readAttr(self, attr):
        attrSet = set()
        for s in attr.split():
            attrSet.add(TypeAttrs.lookup(s))
        return attrSet
    
    def readBase(self, base):
        sigil = base[0]
        name = base[1:]
        if sigil == '.':
            return self.readPrim(name)
        elif sigil == '$':
            return self.readTypeRef(name)
        else:
            return self.readUnnamed(int(name))
    
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
    
    def readPrim(self, name):
        return XmlParser.__primTypes[name]
    
    def readTypeRef(self, name):
        return CTypeRef(name)
    
    def readWrap(self, wrap, t):
        arr = wrap.split()
        i = 0
        while i < len(arr):
            c = arr[i].lower()
            if c == 'a':
                t = CArr(t, int(arr[i + 1]))
                i += 2
            elif c == 'p':
                t = CPtr(t)
                i += 1
            else:
                t = self.readFunc(int(arr[i + 1]), t)
                i += 2
        return t

    def readFunc(self, id, t):
        eFunc = self.__locFunc.find(id)
        t = CFunc(t)
        for eArg in eFunc:
            t.add(self.readType(eArg, True))
        return t


parser = XmlParser('f:\\ntkrnlmp.xml')
named = parser.root[2]

print parser.readGroup(named[5]).define('x', '....', '    ')
