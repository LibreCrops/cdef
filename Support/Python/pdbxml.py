#!/usr/bin/env python3

import sys
import xml.etree.ElementTree as et
from collections import deque
from operator import attrgetter
#====================================================================#
def maybe_space(s):
    return ' ' + s if s else ''

def is_all_capital(s):
    for c in s:
        if not c.isupper() and not c.isdigit():
            return False
    return True

class CType(object):

    def unwrap_to(self, visitor):
        t = self
        while isinstance(t, CWrap):
            t.accept(visitor)
            visitor.after_visit(t)
            t = t.next
        return t

    def _decorate(self, definer, s):
        t = definer._reduct(self)
        decorator = Decorator(definer, s)
        core = t.unwrap_to(decorator)
        return core, decorator.result

    def define(self, var, definer, indent):
        core, s1 = self._decorate(definer, var)
        s2 = indent + core.part_def(definer, indent)
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

    def sig(self, definer):
        core, s1 = self._decorate(definer, '')
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

    def same_as(self, other):
        r = self
        s = other
        while True:
            if (isinstance(r, CWrap) and
                isinstance(s, CWrap) and
                r.same_wrap_as(s)
            ):
                r = r.next
                s = s.next
            else:
                break
        if isinstance(r, CPrim) and isinstance(s, CPrim):
            return r is s
        if isinstance(r, CTypeRef) and isinstance(s, CTypeRef):
            return r.name == s.name
        return False

class CTerm(CType):
    # (abstract) part_def
    pass

class CPrefix(CTerm):
    # (abstract property) prefix
    def part_def(self, definer, indent):
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

    def def_body(self, definer, indent):
        s = ''
        s += indent + '{' + '\n'
        s += self.child_def(definer, indent + definer.tab)
        s += indent + '}'
        return s

    # (impl)
    def part_def(self, definer, indent):
        return self.keyword + '\n' + self.def_body(definer, indent)

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
    def child_def(self, definer, indent):
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
    def child_def(self, definer, indent):
        s = ''
        for e in self.__entries:
            s += definer.define(e.type, e.name, indent)
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

    # (abstract) accept

    def judger(self):
        visitor = SameJudgerVisitor()
        self.accept(visitor)
        return visitor.judger

    def same_wrap_as(self, other):
        visitor = self.judger()
        other.accept(visitor)
        return visitor.same

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

    def __init__(self, definer, s):
        self._definer = definer
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

    def _func_args_str(self, func):
        if not func.args:
            return 'void'
        else:
            return ', '.join(map(lambda t: t.sig(self._definer), func.args))

    @staticmethod
    def _with_call_conv(s, conv):
        if conv is CallConvs.default:
            return s
        else:
            return conv.keyword + ' ' + s

    def visit_func(self, t):
        self._s = (
            self._maybe_paren(Decorator._with_call_conv(self._s, t.call_conv)) +
            '(' + self._func_args_str(t) + ')')

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
            print("warn: need id %d but current id is %s" % (id, child.attrib['id']))
            return self._elem.findall(".//*[@id='%s']" % id)[0]
        return child

class XmlParser(object):
    def __init__(self, path):
        tree = et.parse(path)
        root = tree.getroot()
        self.root = root
        self._loc_func = Locator(root[0])
        self._loc_unnamed = Locator(root[1])
        self._named = root[2]

    def _read_named(self, e_type):
        return self._read_group(e_type)

    def _read_unnamed(self, id):
        e_unnamed = self._loc_unnamed.find(id)
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

    def _read_type(self, e_field, has_wrap):
        attrs = e_field.attrib
        t = self._read_base(attrs['base'])
        if 'attr' in attrs:
            t = CAttrTerm(t, self._read_attr(attrs['attr']))
        if has_wrap:
            t = self._read_wrap(attrs['wrap'], t)
        return t

    def _read_attr(self, attr):
        attr_set = set()
        for s in attr.split():
            attr_set.add(TypeAttrs.lookup(s))
        return attr_set

    def _read_base(self, base):
        sigil = base[0]
        name = base[1:]
        if sigil == '.':
            return self._read_prim(name)
        elif sigil == '$':
            return self._read_type_ref(name)
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

    def _read_type_ref(self, name):
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
        e_func = self._loc_func.find(id)
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

    def choose_into(self, tree_sorter, enum_list):
        for name, impls in self._data.items():
            brace = impls[0].type
            if isinstance(brace, CTree):
                tree_sorter.add(name, brace)
            else:
                enum_list.append((name, brace))

#====================================================================#
class Graph(object):
    def __init__(self):
        self.deps = {}

    def add(self, key, deps):
        self.deps[key] = deps

    def vertices(self):
        return self.deps.keys()

    def get_deps(self, key):
        return self.deps[key]

class TopoSorter(object):
    def __init__(self):
        self.back_deps = {}
        self.num_deps = {}
        self.starters = []

    def add(self, key, deps):
        num_deps = 0
        for dep in deps:
            if dep == key:
                continue
            num_deps += 1
            back_dep_arr = self.back_deps.get(dep)
            if not back_dep_arr:
                back_dep_arr = []
                self.back_deps[dep] = back_dep_arr
            back_dep_arr.append(key)
        self.num_deps[key] = num_deps
        if num_deps == 0:
            self.starters.append(key)

    def read_graph(self, graph):
        for vertex in graph.vertices():
            self.add(vertex, graph.get_deps(vertex))

    def sort(self):
        order = []
        back_deps = self.back_deps
        num_deps = self.num_deps
        num_processed = 0
        num_vertices = len(num_deps)
        queue = deque(self.starters)
        while queue:
            vertex = queue.popleft()
            num_processed += 1
            order.append(vertex)
            for next_vertex in (back_deps.get(vertex) or []):
                num_deps[next_vertex] -= 1
                if num_deps[next_vertex] == 0:
                    queue.append(next_vertex)
        assert num_processed == num_vertices, 'not DAG'
        return order

class TarjanVertex(object):
    def __init__(self):
        self.index = -1
        self.lowlink = -1
        self.on_stack = False

    @property
    def touched(self):
        return self.index >= 0

    def init(self, index):
        self.index = index
        self.lowlink = index

# ref: https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm
class TarjanAlgo(object):
    def __init__(self, graph):
        self.stack = []
        self.index = 0
        self.graph = graph
        self.vertices = graph.vertices()
        self.props = {}
        for vertex in self.vertices:
            self.props[vertex] = TarjanVertex()
        self.indices = {}
        self.groups = []
        self.group_index = 0

    def solve(self):
        for vertex in self.vertices:
            if not self.props[vertex].touched:
                self.strong_connect(vertex)

    def strong_connect(self, vertex):
        self.props[vertex].init(self.index)
        self.index += 1
        self.stack.append(vertex)
        self.props[vertex].on_stack = True

        for next_vertex in self.graph.get_deps(vertex):
            if not self.props[next_vertex].touched:
                self.strong_connect(next_vertex)
                self.props[vertex].lowlink = min(
                    self.props[vertex].lowlink,
                    self.props[next_vertex].lowlink
                )
            elif self.props[next_vertex].on_stack:
                self.props[vertex].lowlink = min(
                    self.props[vertex].lowlink,
                    self.props[next_vertex].index
                )

        if self.props[vertex].lowlink == self.props[vertex].index:
            group = []
            while True:
                this_vertex = self.stack.pop()
                self.props[this_vertex].on_stack = False
                group.append(this_vertex)
                self.indices[this_vertex] = self.group_index
                if this_vertex == vertex:
                    break
            self.groups.append(group)
            self.group_index += 1

    def make_graph(self):
        graph = Graph()
        group_index = 0
        for group in self.groups:
            dep_indices = set()
            for vertex in group:
                for next_vertex in self.graph.get_deps(vertex):
                    next_group_index = self.indices[next_vertex]
                    dep_indices.add(next_group_index)
            graph.add(group_index, list(dep_indices))
            group_index += 1
        return graph

#====================================================================#
class TreeVertex(object):

    def __init__(self, type, dep, use):
        self.type = type
        self.dep = dep
        self.use = use
        self.self_ref = False

class TreeGraph(object):

    def __init__(self, info):
        self._info = info

    def vertices(self):
        return self._info.keys()

    def get_deps(self, key):
        return self._info[key].dep

class TreeSorter(object):

    def __init__(self):
        self._info = {}

    def add(self, name, tree):
        self._info[name] = TreeVertex(tree, *tree.get_dep())

    def pre_sort(self):
        info = self._info
        is_internal = lambda name: name in info
        for v in info.values():
            v.dep = filter(is_internal, v.dep)
            v.use = filter(is_internal, v.use)

    def _make_scc(self):
        graph = TreeGraph(self._info)
        scc = TarjanAlgo(graph)
        scc.solve()
        return scc

    def _sort_scc(self, graph):
        # NOTE: is this step necessary?
        topo = TopoSorter()
        topo.read_graph(graph)
        return topo.sort()

    def sort(self):
        result = []
        scc = self._make_scc()
        scc_graph = scc.make_graph()
        scc_order = self._sort_scc(scc_graph)
        for scc_index in scc_order:
            names = scc.groups[scc_index]
            if len(names) == 1:
                if scc_index in scc_graph.get_deps(scc_index):
                    self._info[names[0]].self_ref = True
                result.append(names)
            else:
                topo = TopoSorter()
                for name in names:
                    topo.add(name,
                             filter(lambda u: scc.indices[u] == scc_index,
                                    self._info[name].use))
                result.append(topo.sort())
        return result

    def get_type(self, name):
        return self._info[name].type

    def is_type_recursive(self, name):
        return self._info[name].self_ref

    def name_list(self):
        return self._info.keys()

#====================================================================#
def try_():
    global st
    s_vt = CStruct()
    method1 = CFunc(PrimTypes.INT)
    method1.add(CPtr(CTypeRef('ICrazy')))
    s_vt.add(method1, 'DoIt')
    s_iface = CStruct()
    s_iface.add(CPtr(CTypeRef('ICrazyVTable')), 'vt')
    s_iface.add(CPtr(CTypeRef('IUnknown')), 'unk')
    s_iface.add(CTypeRef('ICrazyVTable'), 'test_use')
    s_com = CStruct()
    s_com.add(CPtr(CTypeRef('ICrazy')), 'crazier')
    s_node = CStruct()
    s_node.add(CPtr(CTypeRef('Node')), 'prev')
    s_node.add(CPtr(CTypeRef('Node')), 'next')

    storage = Storage()
    storage.begin_file(0)
    storage.add('Node', s_node)
    storage.add('Component', s_com)
    storage.add('ICrazyVTable', s_vt)
    storage.add('ICrazy', s_iface)
    storage.end_file()

    st = TreeSorter()
    storage.choose_into(st, [])

#====================================================================#
class SameWrapVisitor(WrapVisitor):

    def __init__(self):
        self.same = False

class SamePtrVisitor(SameWrapVisitor):

    def visit_ptr(self, t):
        self.same = True

class SameArrVisitor(SameWrapVisitor):

    def __init__(self, arr):
        super(SameArrVisitor, self).__init__()
        self._len = arr.len

    def visit_arr(self, t):
        if t.len == self._len:
            self.same = True

class SameFuncVisitor(SameWrapVisitor):

    def __init__(self, func):
        super(SameFuncVisitor, self).__init__()
        self._args = func.args
        self._expected_len = len(func.args)

    def visit_func(self, t):
        if len(t.args) == self._expected_len:
            same = True
            for i in range(0, self._expected_len):
                if not self._args[i].same_as(t.args[i]):
                    same = False
                    break
            self.same = same

class SameJudgerVisitor(WrapVisitor):

    def __init__(self):
        self.judger = None

    def visit_ptr(self, t):
        self.judger = SamePtrVisitor()

    def visit_arr(self, t):
        self.judger = SameArrVisitor(t)

    def visit_func(self, t):
        self.judger = SameFuncVisitor(t)

    def visit_bits(self, t):
        assert False, 'should not be here'

def try2():
    t1 = CFunc(PrimTypes.VOID)
    t2 = CFunc(PrimTypes.VOID)
    t1.add(PrimTypes.INT)
    t2.add(PrimTypes.INT)
    print(t1.same_as(t2))

class NextStateSetVisitor(WrapVisitor):

    def __init__(self, cur_state):
        self._state = cur_state
        self.set = None

    def visit_ptr(self, t):
        self.set = self._state.ptr_nexts

    def visit_arr(self, t):
        self.set = self._state.arr_nexts

    def visit_func(self, t):
        self.set = self._state.func_nexts

    def visit_bits(self, t):
        assert False, 'should not be here'

class MatcherState(object):

    def __init__(self):
        self.reduction = None
        self.ptr_nexts = []
        self.arr_nexts = []
        self.func_nexts = []

    def has_reduction(self):
        return self.reduction is not None

    def get_next_state_set(self, t):
        visitor = NextStateSetVisitor(self)
        t.accept(visitor)
        return visitor.set

    @staticmethod
    def _find_state(set, r):
        for s, next in set:
            if r.same_wrap_as(s):
                return next
        return None

    def translate(self, r):
        next_state_set = self.get_next_state_set(r)
        return MatcherState._find_state(next_state_set, r)

    def translate_or_grow(self, r):
        next_state_set = self.get_next_state_set(r)
        next_state = MatcherState._find_state(next_state_set, r)
        if next_state is None:
            next_state = MatcherState()
            next_state_set.append((r, next_state))
        return next_state

class MatcherStateAllCapital(object):

    def __init__(self, name):
        self.name = name

    def has_reduction(self):
        return False

    def translate(self, r):
        if isinstance(r, CPtr):
            return MatcherStateAllCapitalPtr(self.name)
        else:
            return None

class MatcherStateAllCapitalPtr(object):

    def __init__(self, name):
        self.name = name

    def has_reduction(self):
        return True

    @property
    def reduction(self):
        return CTypeRef("P" + self.name)

    def translate(self, r):
        return None

class WrapCopyVisitor(object):

    def __init__(self, core):
        self.result = core

    def visit_ptr(self, t):
        self.result = CPtr(self.result)

    def visit_arr(self, t):
        self.result = CArr(self.result, t.len)

    def visit_func(self, t):
        func = CFunc(self.result)
        for arg in t.args:
            func.add(arg)
        self.result = func

class Matcher(object):

    def __init__(self):
        self._starts = {}
        self.tree_names_list = []

    def _tree_exists(self, name):
        return name in self.tree_names_list

    def _get_start_state(self, core):
        if isinstance(core, CTypeRef):
            name = core.name
            if is_all_capital(name) and self._tree_exists(name):
                return MatcherStateAllCapital(name)
            else:
                return None
        else:
            return self._starts.get(core)

    def _get_or_create_start_state(self, base_type):
        state = self._get_start_state(base_type)
        if state is None:
            state = MatcherState()
            self._starts[base_type] = state
        return state

    @staticmethod
    def _expand_type(t):
        stack = []
        while isinstance(t, CWrap):
            stack.insert(0, t)
            t = t.next
        return t, stack

    def add_rule(self, type, name):
        core, wraps = Matcher._expand_type(type)
        assert isinstance(core, CPrefix)
        state = self._get_or_create_start_state(core)
        for wrap in wraps:
            state = state.translate_or_grow(wrap)
        state.reduction = CTypeRef(name)

    def reduct(self, type):
        core, wraps = Matcher._expand_type(type)
        result = core
        succeed = -1
        ahead = 0
        state = self._get_start_state(core)
        while state is not None:
            if state.has_reduction():
                succeed = ahead
                result = state.reduction
            if ahead == len(wraps):
                break
            state = state.translate(wraps[ahead])
            ahead += 1
        if succeed >= 0:
            visitor = WrapCopyVisitor(result)
            for wrap in wraps[succeed:]:
                wrap.accept(visitor)
            return visitor.result
        else:
            return type

def try3():
    global m
    m = Matcher()
    m.add_rule(PrimTypes.INT, 'INT')
    m.add_rule(CPtr(PrimTypes.INT), 'PINT')
    m.add_rule(CPtr(CPtr(PrimTypes.VOID)), 'PPVOID')
    t1 = PrimTypes.INT
    print(m.reduct(t1).define('x', '....', '    '))

# try3()
#====================================================================#
class Definer(object):

    def __init__(self, tab = '    '):
        self.tab = tab
        self.matcher = Matcher()

    def define(self, type, var, indent = ''):
        return type.define(var, self, indent)

    def sig(self, type):
        return type.sig

    def _reduct(self, type):
        return self.matcher.reduct(type)

class BraceDefMaker(object):

    END_DEF = ';\n'

    @staticmethod
    def make_typedef_args(type, name):
        if isinstance(type, CEnum) or not is_all_capital(name):
            return name;
        else:
            return name + ', *P' + name

    @staticmethod
    def make_inner_names(type, name):
        inner_name = '_' + name
        if isinstance(type, CEnum):
            mixed_inner_name = ''
        else:
            mixed_inner_name = inner_name
        return inner_name, mixed_inner_name

    def __init__(self, name, type, definer):
        self._inner_name, self._mixed_inner_name = (
            BraceDefMaker.make_inner_names(type, name))
        self._typedef_args = (
            BraceDefMaker.make_typedef_args(type, name))
        self._type = type
        self._definer = definer

    def pure_def(self, indent = ''):
        return (
            indent + self._type.qualified_name(self._inner_name) + '\n' +
            self._type.def_body(self._definer, indent) +
            BraceDefMaker.END_DEF)

    def _typedef(self, indent, inner_name, def_body):
        return (
            indent + "typedef " + self._type.qualified_name(inner_name) +
            def_body + " " + self._typedef_args +
            BraceDefMaker.END_DEF)

    def typedef(self, indent = ''):
        return self._typedef(indent, self._inner_name, '')

    def mixed_def(self, indent = ''):
        return self._typedef(
            indent,
            self._mixed_inner_name,
            '\n' + self._type.def_body(self._definer, indent))

def try5():
    d = Definer()
    m = d.matcher
    f1 = CFunc(PrimTypes.INT)
    f1.add(CPtr(CPtr(PrimTypes.VOID)))
    m.add_rule(CPtr(PrimTypes.VOID), 'PVOID')
    m.add_rule(PrimTypes.INT, 'INT')
    m.tree_names_list.append('MYSTRUC')
    # m.add_rule(CPtr(f1), 'MY_PROC')
    s1 = CStruct()
    s1.add(PrimTypes.UINT, 'a')
    u1 = CUnion()
    u1.add(PrimTypes.CHAR, 'b1')
    u1.add(CPtr(CTypeRef('MYSTRUC')), 'b2')
    s1.add(u1, '')
    s1.add(PrimTypes.INT, 'c')
    # mk = BraceDefMaker('TEST_16', s1, d)
    e1 = CEnum()
    e1.add('RED', 10)
    e1.add('GREEN', 20)
    e1.add('BLUE', 30)
    mk = BraceDefMaker('TEST16', e1, d)
    print(mk.typedef())
    print(mk.pure_def())
    print(mk.mixed_def())

# try5()

#====================================================================#
def setup_goo_matcher(m):
    for i in dir(PrimTypes):
        if i.isupper():
            m.add_rule(attrgetter(i)(PrimTypes), i)
#====================================================================#
class Session(object):

    def __init__(self):
        self._storage = Storage()
        self._file_index = 0

    def load(self, file_path):
        parser = XmlParser(file_path)
        self._storage.begin_file(self._file_index)
        parser.read_to_storage(self._storage)
        self._storage.end_file()
        self._file_index += 1

    def write_header(self, file_handle = sys.stdout):
        tree_sorter = TreeSorter()
        enum_list = []
        self._storage.choose_into(tree_sorter, enum_list)
        tree_sorter.pre_sort()
        groups = tree_sorter.sort()
        definer = Definer()
        setup_goo_matcher(definer.matcher)
        definer.matcher.tree_names_list= tree_sorter.name_list()

        separator = ('/' * 79) + '\n'

        file_handle.write(separator)

        for name, type in enum_list:
            file_handle.write(BraceDefMaker(name, type, definer).mixed_def())
            file_handle.write('\n')

        file_handle.write(separator)

        for group in groups:
            if (len(group) == 1 and
                not tree_sorter.is_type_recursive(group[0])
            ):
                name = group[0]
                type = tree_sorter.get_type(name)
                file_handle.write(BraceDefMaker(name, type, definer).mixed_def())
                file_handle.write('\n')

            else:
                makers = [BraceDefMaker(
                    name, tree_sorter.get_type(name), definer)
                    for name in group]

                for maker in makers:
                    file_handle.write(maker.typedef())
                file_handle.write('\n')

                for maker in makers:
                    file_handle.write(maker.pure_def())
                file_handle.write('\n')

    def write_header_to_file(self, file_path):
        f = open(file_path, 'w')
        self.write_header(f)
        f.close()

#====================================================================#
s = Session()
for i in sys.argv[1:]:
    s.load(i)
    s.write_header()
