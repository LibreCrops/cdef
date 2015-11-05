from .ctype import CPrim


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


PRIMTYPES = [prim for prim in dir() if prim.isupper()]


def setup_goo_matcher(matcher):
    for i in PRIMTYPES:
        matcher.add_rule(globals()[i], i)
