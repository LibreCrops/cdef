using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    abstract class CPrefix : CTerm
    {
        public abstract string Prefix { get; }
        public override string PartDef(string indent, string tab)
        {
            return Prefix;
        }
    }
}
