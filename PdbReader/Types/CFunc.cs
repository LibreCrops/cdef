using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    class CFunc : CWrap
    {
        private List<CType> _args;
        public CFunc(CType retType)
            : base(retType)
        {
            _args = new List<CType>();
        }
        public CType RetType
        {
            get { return _next; }
        }
        public void Add(CType type)
        {
            _args.Add(type);
        }
        public override string Decorate(string s)
        {
            return s + "(" + string.Join(", ", _args.Select(a => a.Sig)) + ")";
        }
        public override void Accept(IWrapVisitor visitor)
        {
            visitor.VisitFunc(this);
        }
    }
}
