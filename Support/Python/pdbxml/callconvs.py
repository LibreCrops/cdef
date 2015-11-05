class CallConv(object):
    def __init__(self, keyword):
        self.keyword = keyword

class CallConvs(object):
    default = CallConv(None)
    stdcall = CallConv('__stdcall')
    cdecl = CallConv('__cdecl')
