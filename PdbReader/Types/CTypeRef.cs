using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    class CTypeRef : CPrefix
    {
        private string _name;
        public CTypeRef(string name)
        {
            _name = name;
        }
        public override string Prefix
        {
            get { return _name; }
        }
        public string Name
        {
            get { return _name; }
        }
    }
}
