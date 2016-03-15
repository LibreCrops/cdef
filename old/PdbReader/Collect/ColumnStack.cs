using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Collect
{
    class ColumnStack
    {
        private Stack<Column> _stack;
        public ColumnStack()
        {
            _stack = new Stack<Column>();
        }
        public void Adjoin(Column column, out Column resetted)
        {
            if (_stack.Count == 0)
            {
                _stack.Push(column);
                resetted = null;
                return;
            }
            Column newColumn = column;
            Column curColumn;
            for (; ; )
            {
                // 在找到被重置的列之前，堆栈不可能被挖空
                // 最糟糕的情况，就是被重置的列正好是最底一列
                curColumn = _stack.Peek();
                if (curColumn.IsAbove(newColumn))
                {
                    resetted = curColumn;
                    _stack.Push(newColumn);
                    return;
                }
                if (curColumn.IsParallelTo(newColumn))
                {
                    resetted = curColumn;
                    _stack.Pop();
                    _stack.Push(newColumn);
                    return;
                }
                _stack.Pop();
            }
        }
    }
}
