using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace PdbReader.Types
{
    abstract class CType
    {
        protected static string MaybeSpace(string s)
        {
            if (string.IsNullOrEmpty(s))
            {
                return "";
            }
            else
            {
                return " " + s;
            }
        }

        public string Wrap(string var, out CType core)
        {
            string s = var;
            CType t = this;
            CWrap w;
            while ((w = t as CWrap) != null)
            {
                s = w.Decorate(s);
                t = w.Next;
            }
            core = t;
            return s;
        }
        public string Define(string var, string indent, string tab)
        {
            CType core1;
            CTerm core2;
            string s1, s2;

            s1 = Wrap(var, out core1);
            core2 = (CTerm)core1;

            s2 = indent + core2.PartDef(indent, tab);
            return s2 + MaybeSpace(s1) + ";\n";
        }
        public string Sig
        {
            get
            {
                CType core1;
                CPrefix core2;
                string s1, s2;

                s1 = Wrap("", out core1);
                Debug.Assert(core1 is CPrefix);

                core2 = (CPrefix)core1;
                s2 = core2.Prefix;
                return s2 + MaybeSpace(s1);
            }
        }
    }
}
