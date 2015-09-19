using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Dia2Lib;
using PdbReader.Types;

namespace PdbReader.Collect
{
    class Collector
    {
        private Translator _translator;
        public Collector(Translator translator)
        {
            _translator = translator;
        }

        public CStruct CollectStruct(IDiaEnumSymbols symbols)
        {
            LeafMembers allMembers = new LeafMembers(symbols);
            Columns columns = allMembers.CalculateColumns();
            columns.CalculateResetters();
            AnonymousStruct struc = columns.CollectStruct();
            struc.PostProcess();
            struc.SinglizeStructs();
            return (CStruct)struc.ToCType(_translator);
        }

        public CUnion CollectUnion(IDiaEnumSymbols symbols)
        {
            LeafMembers allMembers = new LeafMembers(symbols);
            Columns columns = allMembers.CalculateColumns();
            columns.CalculateResetters();
            AnonymousUnion union = columns.CollectUnion();
            union.PostProcess();
            union.SinglizeStructs();
            return (CUnion)union.ToCType(_translator);
        }
    }
}
