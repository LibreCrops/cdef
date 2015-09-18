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
                Offset maxBotOffset = union.PostProcessWithCut(out lastStruct, out beginIndex);
                if (beginIndex >= 0)
                {
                    lastStruct.TransferMembers(beginIndex, this);
                }

                return maxBotOffset;
            }
            else
            {
                return ((LeafMember)lastMember).BotOffset;
            }
        }
        public Offset PostProcessWithoutCut()
        {
            return PostProcess1();
        }

        private int FindCutPoint(Offset offset)
        {
            for (int i = 1; i < _members.Count; i++)
            {
                Member member = _members[i];
                Offset memberOffset = member.TopOffset;
                if (offset.IsEqualTo(memberOffset))
                {
                    return i;
                }
                if (offset.IsLessThan(memberOffset))
                {
                    return i;
                }
            }
            return -1;
        }
        public Offset PostProcessWithCut(Offset cutOffset, out int cutIndex, out Offset botOffset)
        {
            Offset offset = PostProcess1();
            cutIndex = FindCutPoint(cutOffset);
            botOffset = _members[cutIndex - 1].BotOffset;
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

        public override Offset BotOffset
        {
            get { throw new NotImplementedException(); }
        }
    }
}
