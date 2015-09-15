using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Dia2Lib;

namespace PdbReader.Collect
{
    class LeafMembers
    {
        private List<LeafMember> _members;
        public LeafMembers(IDiaEnumSymbols symbols)
        {
            _members = new List<LeafMember>();
            foreach (IDiaSymbol symbol in symbols)
            {
                _members.Add(new LeafMember(symbol));
            }
        }
        public LeafMember this[int index]
        {
            get { return _members[index]; }
        }
        public int Count
        {
            get { return _members.Count; }
        }
        public Columns CalculateColumns()
        {
            Columns columns = new Columns();
            Column lastColumn = null;
            Offset lastOffset = Offset.Zero;

            int count = _members.Count;
            for (int i = 0; i < count; i++)
            {
                Offset thisOffset = this[i].TopOffset;
                if (thisOffset.IsLessThanOrEqualTo(lastOffset))
                {
                    if (lastColumn != null)
                    {
                        lastColumn.SetEnd(i);
                    }
                    Column col = new Column(this, i);
                    columns.Add(col);
                    lastColumn = col;
                }
                lastOffset = thisOffset;
            }
            lastColumn.SetEnd(count);

            return columns;
        }
    }
}
