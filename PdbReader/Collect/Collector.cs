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

/*
            int i = 0;
            foreach (Column col in columns)
            {
                Console.WriteLine("Column: " + i);
                foreach(Column col2 in col.Resetters)
                {
                    Console.WriteLine("  " + col2.ToString());
                }
                i++;
            }

            struc = columns.CollectStruct();
            Console.WriteLine("==========");
            struc.WriteOut();
            struc.PostProcess();
            Console.WriteLine("==========");
            struc.WriteOut();
            struc.SinglizeStructs();
            Console.WriteLine("==========");
            struc.WriteOut();
 */
        }
    }
}
