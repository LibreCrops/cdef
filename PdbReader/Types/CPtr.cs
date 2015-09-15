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
        public override string Decorate(string s)
        {
            if (_next is CArr || _next is CFunc)
            {
                return "(*" + s + ")";
            }
            else
            {
                return "*" + s;
            }
        }
    }
}
