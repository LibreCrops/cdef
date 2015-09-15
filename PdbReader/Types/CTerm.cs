using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    abstract class CTerm : CType
    {
        public abstract string PartDef(string indent, string tab);
    }
}
