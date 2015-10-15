using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    class CallConv
    {
        private string _keyword;
        public CallConv(string keyword)
        {
            _keyword = keyword;
        }

        public string Keyword
        {
            get { return _keyword; }
        }
    }
}
