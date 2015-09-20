using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Dia2Lib;
using PdbReader.Types;

namespace PdbReader
{
    class PdbSymbol
    {
        private IDiaSymbol _symbol;
        private string _name;
        private PdbSymbolType _type;

        public PdbSymbol(IDiaSymbol symbol, string name, PdbSymbolType type)
        {
            _symbol = symbol;
            _name = name;
            _type = type;
        }

        public static bool IsUnnamed(IDiaSymbol symbol)
        {
            return symbol.name.Contains('<');
        }
        public static string GetInternName(IDiaSymbol symbol)
        {
            string name = symbol.name;
            return name.StartsWith("_") ? name.Substring(1) : name;
        }

        public string Name
        {
            get { return _name; }
        }
        public CBrace TranslateBy(Translator translator)
        {
            return _type.Translate(translator, _symbol);
        }
        public string Keyword
        {
            get { return _type.Keyword; }
        }
    }
}
