using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    class CAttrTerm : CTerm
    {
        private CTerm _type;
        private SortedSet<TypeAttr> _attrs;
        public CAttrTerm(CTerm type, SortedSet<TypeAttr> attrs)
        {
            _type = type;
            _attrs = attrs;
        }
        public CTerm CoreType
        {
            get { return _type; }
        }
        public string AttrStr
        {
            get { return string.Join(" ", _attrs); }
        }
        public override string PartDef(string indent, string tab)
        {
            return AttrStr + " " + _type.PartDef(indent, tab);
        }
    }
}
