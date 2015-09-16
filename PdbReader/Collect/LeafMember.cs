using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Dia2Lib;
using PdbReader.Types;

namespace PdbReader.Collect
{
    class LeafMember : Member
    {
        private IDiaSymbol _symbol;
        private Offset _offset;
        public LeafMember(IDiaSymbol symbol)
        {
            _symbol = symbol;
            _offset = Offset.FromDiaSymbol(symbol);
        }
        public override Offset TopOffset
        {
            get { return _offset; }
        }
        public Offset BottomOffset
        {
            get { return Offset.BottomOffsetFromDiaSymbol(_symbol); }
        }

        public override CType ToCType(Translator translator)
        {
            return translator.TranslateMember(_symbol);
        }
        public override string Name
        {
            get { return _symbol.name; }
        }

        public override void WriteOut(string indent)
        {
            Console.WriteLine(
                string.Format(
                    "{0}{1,-6}{2}",
                    indent,
                    "+" + _offset.Bytes,
                    _symbol.name
                )
            );
        }
    }
}
