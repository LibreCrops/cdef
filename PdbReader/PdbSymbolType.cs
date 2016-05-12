using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Dia2Lib;
using PdbReader.Types;

namespace PdbReader
{
    abstract class PdbSymbolType
    {
        public abstract string Keyword { get; }
        public abstract CBrace Translate(Translator translator, IDiaSymbol symbol);

        public class Type_Struct : PdbSymbolType
        {
            public override string Keyword { get { return "STRUCT"; } }
            public override CBrace Translate(Translator translator, IDiaSymbol symbol)
            {
                return translator.TranslateStruct(symbol);
            }
        }
        public class Type_Union : PdbSymbolType
        {
            public override string Keyword { get { return "UNION"; } }
            public override CBrace Translate(Translator translator, IDiaSymbol symbol)
            {
                return translator.TranslateUnion(symbol);
            }
        }
        public class Type_Enum : PdbSymbolType
        {
            public override string Keyword { get { return "ENUM"; } }
            public override CBrace Translate(Translator translator, IDiaSymbol symbol)
            {
                return translator.TranslateEnum(symbol);
            }
        }
    }
}
