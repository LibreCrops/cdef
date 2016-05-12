using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    class CUnion : CTree
    {
        public override string Keyword
        {
            get { return "union"; }
        }
    }
}
