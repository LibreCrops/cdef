using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PdbReader.Types;

namespace PdbReader.Defs
{
    abstract class Def
    {
        protected CBrace _type;
        public Def(CBrace type)
        {
            _type = type;
        }
        public abstract string Output(string indent, string tab);

        protected static string END_DEF = ";\n";
    }
}
