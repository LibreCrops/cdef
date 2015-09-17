using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PdbReader.Types;

namespace PdbReader.Collect
{
    class AnonymousUnion : TreeMember
    {
        public Offset PostProcessWithCut(out AnonymousStruct lastStruct, out int beginIndex)
        {
            // just to satisfy c# compiler (can't you be smarter?)
            beginIndex = -1;

            AnonymousStruct last = (AnonymousStruct)_members.Last();
            Offset maxBottomOffset = Offset.Zero;
            
            foreach (AnonymousStruct struc in _members)
            {
                Offset offset;
                if (object.ReferenceEquals(last, struc))
                {
                    offset = struc.PostProcessWithCut(maxBottomOffset, out beginIndex);
                }
                else
                {
                    offset = struc.PostProcessWithoutCut();
                }
                maxBottomOffset = Offset.Max(offset, maxBottomOffset);
            }
            lastStruct = last;
            return maxBottomOffset;
        }
        public void PostProcessWithoutCut()
        {
            foreach (AnonymousStruct struc in _members)
            {
                struc.PostProcessWithoutCut();
            }
        }
        public void PostProcess()
        {
            PostProcessWithoutCut();
        }
        public void SinglizeStructs()
        {
            for (int i = 0; i < _members.Count; i++)
            {
                AnonymousStruct struc = (AnonymousStruct)_members[i];
                // TODO: any optimization here?
                struc.SinglizeStructs();
                if (struc.Members.Count == 1)
                {
                    _members[i] = struc.Members[0];
                }
            }
        }
        public override CTree CreateCType()
        {
            return new CUnion();
        }
    }
}
