using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PdbReader.Types;

namespace PdbReader.Xml
{
    class AttrWrapMaker : IWrapVisitor
    {
        private XmlMaker _maker;
        private string _val;
        public AttrWrapMaker(XmlMaker maker)
        {
            _val = "";
            _maker = maker;
        }

        public string Value
        {
            get { return _val == "" ? _val : _val.Substring(1); }
        }

        public void AfterVisit(CWrap type)
        {
        }

        public void VisitArr(CArr arr)
        {
            _val = " a " + arr.Len + _val;
        }

        public void VisitPtr(CPtr ptr)
        {
            _val = " p" + _val;
        }

        public void VisitFunc(CFunc func)
        {
            string letter = object.ReferenceEquals(func.CallConv, CallConvs.Default)
                ? "f"
                : "F";
            _val = " " + letter + " " + _maker.AddFunc(func) + _val;
        }

        public void VisitBits(CBits bits)
        {
            throw new InvalidOperationException();
        }
    }
}
