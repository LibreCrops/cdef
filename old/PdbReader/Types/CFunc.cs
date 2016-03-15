using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    class CFunc : CWrap
    {
        private List<CType> _args;
        private CallConv _callConv;

        public CFunc(CType retType)
            : this(retType, CallConvs.Default)
        {
        }
        public CFunc(CType retType, CallConv callConv)
            : base(retType)
        {
            _args = new List<CType>();
            _callConv = callConv;
        }
        public CType RetType
        {
            get { return _next; }
        }
        public CallConv CallConv
        {
            get { return _callConv; }
        }
        public List<CType> Args
        {
            get { return _args; }
        }
        public void Add(CType type)
        {
            _args.Add(type);
        }
        public override void Accept(IWrapVisitor visitor)
        {
            visitor.VisitFunc(this);
        }
    }
}
