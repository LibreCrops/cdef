using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    class CPrim : CPrefix
    {
        private string _name;
        public CPrim(string name)
        {
            _name = name;
        }
        public override string Prefix
        {
            get { return _name; }
        }
    }
}
