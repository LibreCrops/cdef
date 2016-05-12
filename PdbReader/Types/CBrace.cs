using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    abstract class CBrace : CTerm
    {
        public abstract string Keyword { get; }
        public abstract string ChildDef(string indent, string tab);
        internal string QualifiedName(string innerName)
        {
            return Keyword + MaybeSpace(innerName);
        }
        internal string DefBody(string indent, string tab)
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine(indent + "{");
            sb.Append(ChildDef(indent + tab, tab));
            sb.Append(indent + "}");
            return sb.ToString();
        }
        public override string PartDef(string indent, string tab)
        {
            return Keyword + "\n" + DefBody(indent, tab);
        }
    }
}
