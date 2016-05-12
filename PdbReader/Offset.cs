using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Dia2Lib;
using PdbReader.DiaExtra;

namespace PdbReader
{
    class Offset
    {
        private int _bytes;
        private int _bits;
        public Offset(int bytes)
            : this(bytes, 0)
        {
        }
        public Offset(int bytes, int bits)
        {
            _bytes = bytes;
            _bits = bits;
            Normalize();
        }
        private void Normalize()
        {
            while (_bits >= 8)
            {
                _bits -= 8;
                _bytes++;
            }
        }

        public int Bytes
        {
            get { return _bytes; }
        }
        public int Bits
        {
            get { return _bits; }
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
                    obj._bytes += (int)symbol.type.length;
                    break;
                case LocationTypeEnum.LocIsBitField:
                    obj._bits += (int)symbol.length;
                    obj.Normalize();
                    break;
            }
            return obj;
        }

        public bool IsEqualTo(Offset o)
        {
            return this._bytes == o._bytes && this._bits == o._bits;
        }
        public bool IsLessThan(Offset o)
        {
            return this._bytes < o._bytes || (this._bytes == o._bytes && this._bits < o._bits);
        }
        public bool IsLessThanOrEqualTo(Offset o)
        {
            return this._bytes < o._bytes || (this._bytes == o._bytes && this._bits <= o._bits);
        }

        public static Offset Max(Offset a, Offset b)
        {
            return a.IsLessThan(b) ? b : a;
        }
        public static Offset Diff(Offset a, Offset b)
        {
            // assume a <= b
            int bytes = b._bytes - a._bytes;
            int bits = b._bits - a._bits;
            if (bits < 0)
            {
                bits += 8;
                bytes--;
            }
            return new Offset(bytes, bits);
        }

        public override string ToString()
        {
            if (this._bits != 0)
            {
                return this._bytes + "." + this._bits;
            }
            else
            {
                return this._bytes + "";
            }
        }

        public static Offset Neg    = new Offset(-1);
        public static Offset Zero   = new Offset(0);
        public static Offset One    = new Offset(1);
    }
}
