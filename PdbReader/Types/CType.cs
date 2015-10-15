using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace PdbReader.Types
{
    abstract class CType
    {
        public void UnwrapTo(IWrapVisitor visitor, out CTerm core)
        {
            CType t = this;
            CWrap w;
            while ((w = t as CWrap) != null)
            {
                w.Accept(visitor);
                visitor.AfterVisit(w);
                t = w.Next;
            }
            core = (CTerm)t;
        }

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

        private string Decorate(string var, out CTerm core)
        {
            Decorator decorator = new Decorator(var);
            UnwrapTo(decorator, out core);
            return decorator.Result;
        }
        public string Define(string var, string indent, string tab)
        {
            CTerm core;
            string s1, s2;

            s1 = Decorate(var, out core);

            s2 = indent + core.PartDef(indent, tab);
            return s2 + MaybeSpace(s1) + ";\n";
        }
        private string TryGetPrefix(CType t)
        {
            string s;
            try
            {
                if (t is CAttrTerm)
                {
                    CAttrTerm t2 = (CAttrTerm)t;
                    s = t2.AttrStr + " " + ((CPrefix)t2.CoreType).Prefix;
                }
                else
                {
                    s = ((CPrefix)t).Prefix;
                }
            }
            catch (InvalidCastException)
            {
                throw new InvalidOperationException();
            }
            return s;
        }
        public string Sig
        {
            get
            {
                CTerm core;
                string s1, s2;

                s1 = Decorate("", out core);
                s2 = TryGetPrefix(core);
                return s2 + MaybeSpace(s1);
            }
        }
    }
}
