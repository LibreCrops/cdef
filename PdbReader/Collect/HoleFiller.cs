using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PdbReader.Types;

namespace PdbReader.Collect
{
    class HoleFiller
    {
        private string _prefix;
        private int _num;
        private CType _type;
        public HoleFiller()
            : this("__hole_")
        {
        }
        public HoleFiller(string prefix)
        {
            _prefix = prefix;
            _num = 0;
        }
        public bool Check(Offset lastBot, Offset thisTop)
        {
            Offset diff = Offset.Diff(lastBot, thisTop);
            if (diff.IsLessThan(Offset.One)) { return false; }

            _type = new CArr(PrimTypes.CHAR, diff.Bytes);
            _num++;
            return true;
        }
        public CType FieldType
        {
            get { return _type; }
        }
        public string FieldName
        {
            get { return _prefix + _num; }
        }
    }
}
