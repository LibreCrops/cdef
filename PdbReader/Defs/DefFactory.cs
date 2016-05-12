using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PdbReader.Types;

namespace PdbReader.Defs
{
    class DefFactory
    {
        private string _innerPrefix;
        public DefFactory()
            : this("_")
        {
            
        }
        public DefFactory(string prefix)
        {
            _innerPrefix = prefix;
        }

        private string InnerName(string s)
        {
            return "_" + s;
        }
        private bool IsFullCapital(string s)
        {
            return s.All(c => !char.IsLetter(c) || char.IsUpper(c));
        }
        private string TypedefArgs(CBrace type, string name)
        {
            if (type is CEnum || !IsFullCapital(name))
            {
                return name;
            }
            else
            {
                return name + ", *P" + name;
            }
        }
        private string MixedInnerName(CBrace type, string name)
        {
            if (type is CEnum)
            {
                return "";
            }
            else
            {
                return InnerName(name);
            }
        }

        public Def CreatePureDef(CBrace type, string name)
        {
            return new PureDef(
                type,
                InnerName(name)
            );
        }
        public Def CreateTypedef(CBrace type, string name)
        {
            return new Typedef(
                type,
                InnerName(name),
                TypedefArgs(type, name)
            );
        }
        public Def CreateMixedTypedef(CBrace type, string name)
        {
            return new MixedTypedef(
                type,
                MixedInnerName(type, name),
                TypedefArgs(type, name)
            );
        }
    }
}
