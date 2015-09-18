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
        private Offset _top;
        private Offset _bot;
        public LeafMember(IDiaSymbol symbol)
        {
            _symbol = symbol;
            _top = Offset.FromDiaSymbol(symbol);
            _bot = Offset.BottomOffsetFromDiaSymbol(symbol);
        }
        public override Offset TopOffset
        {
            get { return _top; }
        }
        public override Offset BotOffset
        {
            get { return _bot; }
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
                    "{0}{1,-8}{2}",
                    indent,
                    "+" + _top.ToString(),
                    _symbol.name
                )
            );
        }
    }
}
