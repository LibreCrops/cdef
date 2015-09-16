using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    class TypeAttr : IComparable<TypeAttr>
    {
        private string _text;
        private int _num;
        public TypeAttr(string text)
            : this(text, 0)
        {
        }
        public TypeAttr(string text, int num)
        {
            _text = text;
            _num = num;
        }
        public int CompareTo(TypeAttr b)
        {
            TypeAttr a = this;
            return a._num.CompareTo(b._num);
        }
        public override string ToString()
        {
            return _text;
        }
    }
}
