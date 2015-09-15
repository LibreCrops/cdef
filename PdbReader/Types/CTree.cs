using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    abstract class CTree : CBrace
    {
        protected List<Entry> _entries;
        public class Entry
        {
            private CType _type;
            private string _name;
            public Entry(CType type, string name)
            {
                _type = type;
                _name = name;
            }
            public CType Type
            {
                get { return _type; }
            }
            public string Name
            {
                get { return _name; }
            }
        }
        public CTree()
        {
            _entries = new List<Entry>();
        }
        public void Add(CType type, string name)
        {
            _entries.Add(new Entry(type, name));
        }
        public List<Entry> Members
        {
            get { return _entries; }
        }
        public override string ChildDef(string indent, string tab)
        {
            StringBuilder sb = new StringBuilder();
            foreach (Entry e in _entries)
            {
                sb.Append(e.Type.Define(e.Name, indent, tab));
            }
            return sb.ToString();
        }
    }
}
