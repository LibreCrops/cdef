using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PdbReader.Types;

namespace PdbReader.Collect
{
    class AnonymousStruct : TreeMember
    {
        private Offset PostProcess1()
        {
            Member lastMember = _members.Last();
            if (lastMember is AnonymousUnion)
            {
                AnonymousUnion union = (AnonymousUnion)lastMember;
                AnonymousStruct lastStruct;
                int beginIndex;
                Offset maxBottomOffset = union.PostProcessWithCut(out lastStruct, out beginIndex);
                if (beginIndex >= 0)
                {
                    lastStruct.TransferMembers(beginIndex, this);
                }

                return maxBottomOffset;
            }
            else
            {
                return ((LeafMember)lastMember).BottomOffset;
            }
        }
        public Offset PostProcessWithoutCut()
        {
            return PostProcess1();
        }

        private int FindCutPoint(Offset offset)
        {
            for (int i = 0; i < _members.Count; i++)
            {
                Member member = _members[i];
                Offset memberOffset = member.TopOffset;
                if (offset.IsEqualTo(memberOffset))
                {
                    return i;
                }
                if (offset.IsLessThan(memberOffset))
                {
                    // TODO:
                    //   seems getting last member's bottom offset is important
                    //   to detect the gorge caused by aligning
                    throw new InvalidOperationException();
                }
            }
            return -1;
        }
        public Offset PostProcessWithCut(Offset cutOffset, out int cutIndex)
        {
            Offset offset = PostProcess1();
            cutIndex = FindCutPoint(cutOffset);
            return offset;
        }

        private void TransferMembers(int fromIndex, AnonymousStruct another)
        {
            int total = _members.Count;
            for (int i = fromIndex; i < total; i++)
            {
                another._members.Add(_members[i]);
            }
            _members.RemoveRange(fromIndex, total - fromIndex);
        }

        public void PostProcess()
        {
            PostProcessWithoutCut();
        }
        public void SinglizeStructs()
        {
            foreach (Member member in _members)
            {
                if (member is AnonymousUnion)
                {
                    ((AnonymousUnion)member).SinglizeStructs();
                }
            }
        }
        public override CTree CreateCType()
        {
            return new CStruct();
        }
    }
}
