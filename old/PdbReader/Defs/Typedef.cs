using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PdbReader.Types;

namespace PdbReader.Defs
{
    class Typedef : Def
    {
        protected string _innerName;
        protected string _args;
        public Typedef(CBrace type, string innerName, string args)
            : base(type)
        {
            _innerName = innerName;
            _args = args;
        }
        public override string Output(string indent, string tab)
        {
            return
                indent
                + "typedef " + _type.QualifiedName(_innerName)
                + GetBody(indent, tab) + " " + _args + END_DEF;
        }
        protected virtual string GetBody(string indent, string tab)
        {
            return "";
        }
    }
}
