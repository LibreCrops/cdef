using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Collect
{
    class Columns : IEnumerable<Column>
    {
        private List<Column> _columns;
        public Columns()
        {
            _columns = new List<Column>();
        }
        public void Add(Column column)
        {
            _columns.Add(column);
        }

        public void CalculateResetters()
        {
            ColumnStack stack = new ColumnStack();
            foreach (Column column in _columns)
            {
                Column resetted;
                stack.Adjoin(column, out resetted);
                if (resetted == null) { continue; }
                resetted.PushResetter(column);
            }
        }

        public AnonymousStruct CollectStruct()
        {
            return _columns[0].CollectStruct();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return (IEnumerator)GetEnumerator();
        }
        public IEnumerator<Column> GetEnumerator()
        {
            return _columns.GetEnumerator();
        }
    }
}
