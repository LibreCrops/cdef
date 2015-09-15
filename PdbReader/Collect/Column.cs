using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Collect
{
    class Column
    {
        private LeafMembers _allMembers;
        private int _beginIndex;
        private int _endIndex;
        private List<Column> _resetters;
        public Column(LeafMembers members, int beginIndex)
        {
            _allMembers = members;
            _beginIndex = beginIndex;
            _resetters = new List<Column>();
        }
        public void SetEnd(int endIndex)
        {
            _endIndex = endIndex;
        }

        public List<Column> Resetters
        {
            get { return _resetters; }
        }
        public void PushResetter(Column resetter)
        {
            _resetters.Add(resetter);
        }

        public Offset TopOffset
        {
            get { return _allMembers[_beginIndex].TopOffset; }
        }

        public bool IsParallelTo(Column o)
        {
            return this.TopOffset.IsEqualTo(o.TopOffset);
        }
        public bool IsAbove(Column o)
        {
            return this.TopOffset.IsLessThan(o.TopOffset);
        }

        private int FindMatchedMemberIndex(Offset offset)
        {
            for (int i = _beginIndex; ; i++)
            {
                Offset curOffset = _allMembers[i].TopOffset;
                if (offset.IsEqualTo(curOffset))
                {
                    return i;
                }
                if (offset.IsLessThan(curOffset))
                {
                    throw new InvalidOperationException();
                }
            }
        }
        public AnonymousStruct CollectStruct()
        {
            return CollectStruct(_beginIndex, _resetters.Count - 1);
        }
        public AnonymousStruct CollectStruct(int membersIndex, int resetterIndex)
        {
            AnonymousStruct result = new AnonymousStruct();
            if (resetterIndex == -1)
            {
                for (int i = membersIndex; i < _endIndex; i++)
                {
                    result.Add(_allMembers[i]);
                }
                return result;
            }

            Column resetter = _resetters[resetterIndex];
            Offset offset = resetter.TopOffset;
            int nextMembersIndex = FindMatchedMemberIndex(offset);
            for (int i = membersIndex; i < nextMembersIndex; i++)
            {
                result.Add(_allMembers[i]);
            }
            result.Add(CollectUnion(nextMembersIndex, resetterIndex, offset));
            return result;
        }
        public AnonymousUnion CollectUnion(int membersIndex, int resetterIndex, Offset offset)
        {
            AnonymousUnion result = new AnonymousUnion();
            Column curColumn = this;

            for (; ; )
            {
                // determine have we encountered the last parallel column
                if (resetterIndex == -1) { break; }
                
                Column nextColumn = curColumn._resetters[resetterIndex];
                if (!nextColumn.TopOffset.IsEqualTo(offset)) { break; }

                result.Add(curColumn.CollectStruct(membersIndex, resetterIndex - 1));

                curColumn = nextColumn;
                membersIndex = nextColumn._beginIndex;
                resetterIndex = nextColumn._resetters.Count - 1;
            }
            result.Add(curColumn.CollectStruct(membersIndex, resetterIndex));
            return result;
        }

        public override string ToString()
        {
            return string.Format("Column(Begin={0}, End={1})", _beginIndex, _endIndex);
        }
    }
}
