using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    class CPtr : CWrap
    {
        public CPtr(CType next)
            : base(next)
        {
        }
        public override void Accept(IWrapVisitor visitor)
        {
            visitor.VisitPtr(this);
        }
    }
}
