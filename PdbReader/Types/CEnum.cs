using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    class CEnum : CBrace
    {
        public List<Entry> _entries;
        public class Entry
        {
            private string _name;
            private int _val;
            public Entry(string name, int val)
            {
                _name = name;
                _val = val;
            }
            public string Name
            {
                get { return _name; }
            }
            public int Val
            {
                get { return _val; }
            }
        }
        public CEnum()
        {
            _entries = new List<Entry>();
        }
        public void Add(string name, int val)
        {
            _entries.Add(new Entry(name, val));
        }
        public List<Entry> Entries
        {
            get { return _entries; }
        }
        public override string Keyword
        {
            get { return "enum"; }
        }
        public override string ChildDef(string indent, string tab)
        {
            if (_entries.Count == 0) { return ""; }

            StringBuilder sb = new StringBuilder();
            Entry last = _entries.Last();
            foreach (Entry e in _entries)
            {
                sb.Append(indent + e.Name + " = " + e.Val);
                if (!object.ReferenceEquals(e, last)) { sb.Append(','); }
                sb.Append('\n');
            }
            return sb.ToString();
        }
    }
}
