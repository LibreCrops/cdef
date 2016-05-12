using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader
{
    class PdbSymbolTypes
    {
        public static PdbSymbolType Struct = new PdbSymbolType.Type_Struct();
        public static PdbSymbolType Union = new PdbSymbolType.Type_Union();
        public static PdbSymbolType Enum = new PdbSymbolType.Type_Enum();
    }
}
