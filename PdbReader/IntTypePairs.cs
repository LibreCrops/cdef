using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader
{
    static class IntTypePairs
    {
        // no `LONG'. see btLong, btULong
        public static IntTypePair CHAR =
            new IntTypePair(PrimTypes.CHAR, PrimTypes.UCHAR);
        public static IntTypePair INT =
            new IntTypePair(PrimTypes.INT, PrimTypes.UINT);
        public static IntTypePair SHORT =
            new IntTypePair(PrimTypes.SHORT, PrimTypes.USHORT);
        public static IntTypePair LONGLONG =
            new IntTypePair(PrimTypes.LONGLONG, PrimTypes.ULONGLONG);

        public static IntTypePair SelectBySize(int size)
        {
            switch (size)
            {
                case 1:
                    return CHAR;
                case 2:
                    return SHORT;
                case 4:
                    return INT;
                case 8:
                    return LONGLONG;
                default:
                    throw new ArgumentException();
            }
        }
    }
}
