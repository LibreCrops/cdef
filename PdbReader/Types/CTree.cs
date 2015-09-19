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
            private Offset _offset;
            public Entry(CType type, string name)
                : this(type, name, Offset.Zero)
            {
            }
            public Entry(CType type, string name, Offset offset)
            {
                _type = type;
                _name = name;
                _offset = offset;
            }
            public CType Type
            {
                get { return _type; }
            }
            public string Name
            {
                get { return _name; }
            }
            public Offset Offset
            {
                get { return _offset; }
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
