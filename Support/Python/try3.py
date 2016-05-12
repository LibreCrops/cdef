def try3():
    global m
    m = Matcher()
    m.add_rule(PrimTypes.INT, 'INT')
    m.add_rule(CPtr(PrimTypes.INT), 'PINT')
    m.add_rule(CPtr(CPtr(PrimTypes.VOID)), 'PPVOID')
    t1 = PrimTypes.INT
    print(m.reduct(t1).define('x', '....', '    '))

# try3()
