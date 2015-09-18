using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Dia2Lib;
using PdbReader.DiaExtra;

namespace PdbReader.Collect
{
    class Offset
    {
        public int Bytes;
        public int Bits;
        public Offset(int bytes)
            : this(bytes, 0)
        {
        }
        public Offset(int bytes, int bits)
        {
            Bytes = bytes;
            Bits = bits;
        }
        public static Offset FromDiaSymbol(IDiaSymbol sym)
        {
            switch ((LocationTypeEnum)sym.locationType)
            {
                case LocationTypeEnum.LocIsThisRel:
                    return new Offset(sym.offset);
                case LocationTypeEnum.LocIsBitField:
                    return new Offset(sym.offset, (int)sym.bitPosition);
                default:
                    throw new ArgumentException();
            }
        }

        public static Offset BottomOffsetFromDiaSymbol(IDiaSymbol symbol)
        {
            Offset obj = Offset.FromDiaSymbol(symbol);
            switch ((LocationTypeEnum)symbol.locationType)
            {
                case LocationTypeEnum.LocIsThisRel:
                    obj.Bytes += (int)symbol.type.length;
                    break;
                case LocationTypeEnum.LocIsBitField:
                    obj.Bits += (int)symbol.length;
                    while (obj.Bits >= 8)
                    {
                        obj.Bits -= 8;
                        obj.Bytes++;
                    }
                    break;
            }
            return obj;
        }

        public bool IsEqualTo(Offset o)
        {
            return this.Bytes == o.Bytes && this.Bits == o.Bits;
        }
        public bool IsLessThan(Offset o)
        {
            return this.Bytes < o.Bytes || (this.Bytes == o.Bytes && this.Bits < o.Bits);
        }
        public bool IsLessThanOrEqualTo(Offset o)
        {
            return this.Bytes < o.Bytes || (this.Bytes == o.Bytes && this.Bits <= o.Bits);
        }

        public static Offset Max(Offset a, Offset b)
        {
            return a.IsLessThan(b) ? b : a;
        }

        public static Offset Neg = new Offset(-1);
        public static Offset Zero = new Offset(0);
    }
}
