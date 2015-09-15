using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PdbReader.Types;

namespace PdbReader.Defs
{
    class PureDef : Def
    {
        private string _innerName;
        public PureDef(CBrace type, string innerName)
            : base(type)
        {
            _innerName = innerName;
        }
        public override string Output(string indent, string tab)
        {
            return
                indent
                + _type.QualifiedName(_innerName) + "\n"
                + _type.DefBody(indent, tab) + END_DEF;
        }
    }
}
