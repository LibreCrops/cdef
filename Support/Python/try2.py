def try2():
    t1 = CFunc(PrimTypes.VOID)
    t2 = CFunc(PrimTypes.VOID)
    t1.add(PrimTypes.INT)
    t2.add(PrimTypes.INT)
    print(t1.same_as(t2))
