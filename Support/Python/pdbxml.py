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
        return s + ' : ' + str(self.len);

#====================================================================#

