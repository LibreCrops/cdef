using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PdbReader.Types;

namespace PdbReader.Defs
{
    class MixedTypedef : Typedef
    {
        public MixedTypedef(CBrace type, string innerName, string args)
            : base(type, innerName, args)
        {
        }
        protected override string GetBody(string indent, string tab)
        {
            return "\n" + _type.DefBody(indent, tab);
        }
    }
}
