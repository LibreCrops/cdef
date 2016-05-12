from functools import total_ordering


@total_ordering
class TypeAttr(object):
    __hash__ = object.__hash__
    def __init__(self, name, num):
        self.__name = name
        self.__num = num

    def __eq__(self, other):
        return self.__num == other.__num

    def __lt__(self, other):
        return self.__num < other.__num

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
