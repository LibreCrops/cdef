using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PdbReader.Types;

namespace PdbReader.Xml
{
    class AttrWrapMaker : IWrapVisitor
    {
        private string _val;
        private bool _hasBitField;
        private int _bitFieldLen;
        public AttrWrapMaker()
        {
            _val = "";
            _hasBitField = false;
        }

        public string Value
        {
            get { return _val == "" ? _val : _val.Substring(1); }
        }

        public void VisitArr(CArr arr)
        {
            _val = " a " + arr.Len + _val;
        }

        public void VisitPtr(CPtr ptr)
        {
            _val = " p" + _val;
        }

        public void VisitFunc(CFunc func)
        {
            // TODO
            _val = " f " + 1 + _val;
        }

        public void VisitBits(CBits bits)
        {
            _hasBitField = true;
            _bitFieldLen = bits.Len;
        }

        public bool HasBitField
        {
            get { return _hasBitField; }
        }
        public int BitFieldLen
        {
            get { return _bitFieldLen; }
        }
    }
}
