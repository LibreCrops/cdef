from . import callconvs
from .utils import maybe_space, is_all_capital


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


class CAttrTerm(CTerm):
    def __init__(self, type, attrs):
        self.__type = type
        self.__attrs = attrs

    @property
    def core_type(self):
        return self.__type

    @property
    def attr_str(self):
        return ' '.join(attr.name for attr in sorted(self.__attrs))

    # (impl)
    def part_def(self, indent, tab):
        return self.attr_str + ' ' + self.__type.part_def(indent, tab)

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

class CFunc(CWrap):
    def __init__(self, ret_type, call_conv = callconvs.DEFAULT):
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


class CTreeEntry:
    def __init__(self, type, name, offset):
        self.type = type
        self.name = name
        self.offset = offset


class CEnumEntry:
    def __init__(self, name, val):
        self.name = name
        self.val = val


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

    def visit_bits(self, t):
        self.result = CBits(self.result, t.len)


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
        if conv is callconvs.DEFAULT:
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
        self.set = []
