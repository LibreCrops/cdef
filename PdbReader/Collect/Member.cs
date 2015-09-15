using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PdbReader.Types;

namespace PdbReader.Collect
{
    abstract class Member
    {
        public abstract Offset TopOffset { get; }

        public abstract CType ToCType(Translator translator);
        public abstract string Name { get; }

        public abstract void WriteOut(string indent);
        public void WriteOut() { WriteOut(""); }
    }
}
