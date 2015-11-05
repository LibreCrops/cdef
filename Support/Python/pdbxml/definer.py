from .ctype import (
    CWrap, CPrefix, CTypeRef, CPtr, CEnum,
    WrapCopyVisitor, NextStateSetVisitor
)
from .utils import is_all_capital


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
        assert not isinstance(r, CBits)
        next_state = MatcherState._find_state(next_state_set, r)
        if next_state is None:
            next_state = MatcherState()
            next_state_set.append((r, next_state))
        return next_state


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
