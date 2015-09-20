using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PdbReader.Types;

namespace PdbReader.Collect
{
    abstract class TreeMember : Member
    {
        protected List<Member> _members;
        public TreeMember()
        {
            _members = new List<Member>();
        }
        public void Add(Member member)
        {
            _members.Add(member);
        }
        public List<Member> Members
        {
            get { return _members; }
        }

        public override Offset TopOffset
        {
            get { return _members.First().TopOffset; }
        }

        public override CType ToCType(Translator translator)
        {
            CTree tree = CreateCType();
            foreach (Member member in _members)
            {
                tree.Add(member.ToCType(translator), member.Name, member.TopOffset);
            }
            return tree;
        }
        public override string Name
        {
            get { return ""; }
        }

        public abstract CTree CreateCType();

        public override void WriteOut(string indent)
        {
            string name = this is AnonymousStruct ? "struct" : "union";
            Console.WriteLine(indent + name);

            string indent2 = indent + "....";
            foreach (Member member in _members)
            {
                member.WriteOut(indent2);
            }
        }
    }
}
