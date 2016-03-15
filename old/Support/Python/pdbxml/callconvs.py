class CallConv(object):
    def __init__(self, keyword):
        self.keyword = keyword


DEFAULT = CallConv(None)
STDCALL = CallConv('__stdcall')
CDECL = CallConv('__cdecl')
