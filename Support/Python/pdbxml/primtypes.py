from .ctype import CPrim


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


def setup_goo_matcher(m):
    for i in dir(PrimTypes):
        if i.isupper():
            m.add_rule(getattr(PrimTypes, i), i)
