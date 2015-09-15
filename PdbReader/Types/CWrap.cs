using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    abstract class CWrap : CType
    {
        protected CType _next;
        public CWrap(CType next)
        {
            _next = next;
        }
        public CType Next
        {
            get { return _next; }
        }
        public abstract string Decorate(string s);
    }
}
