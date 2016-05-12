using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PdbReader.Types;

namespace PdbReader
{
    class IntTypePair
    {
        private CPrim _signed;
        private CPrim _unsigned;
        public IntTypePair(CPrim signed, CPrim unsigned)
        {
            _signed = signed;
            _unsigned = unsigned;
        }
        public CPrim Signed
        {
            get { return _signed; }
        }
        public CPrim Unsigned
        {
            get { return _unsigned; }
        }
    }
}
