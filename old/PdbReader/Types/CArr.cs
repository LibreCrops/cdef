using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    class CArr : CWrap
    {
        private int _len;
        public CArr(CType next, int len)
            : base(next)
        {
            _len = len;
        }
        public int Len
        {
            get { return _len; }
        }
        public override void Accept(IWrapVisitor visitor)
        {
            visitor.VisitArr(this);
        }
    }
}
