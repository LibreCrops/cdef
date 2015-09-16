using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    class CBits : CWrap
    {
        private int _len;
        // TODO: how about make a class CInt
        public CBits(CTerm baseType, int len)
            : base(baseType)
        {
            _len = len;
        }
        public override string Decorate(string s)
        {
            return s + " : " + _len;
        }
    }
}
