using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Dia2Lib;
using PdbReader.Types;
using PdbReader.Defs;

namespace PdbReader
{
    class Program
    {
        const string DOT = "....";
        const string TAB = "    ";
        static void TypesTest()
        {
            CType t1 = new CPrim("int");
            CType t2 = new CPrim("float");
            // CType t2 = new CPtr(t);
            // CType t3 = new CPtr(new CArr(t, 10));

            //CEnum e1 = new CEnum();
            //e1.Add("RED", 0);
            //e1.Add("GREEN", 1);
            //e1.Add("BLUE", 2);

            CStruct s1 = new CStruct();
            s1.Add(t1, "a");

            CFunc f2 = new CFunc(t1);
            CFunc f1 = new CFunc(new CPtr(f2));
            f1.Add(new CPtr(new CPtr(t1)));

            s1.Add(new CArr(new CPtr(f1), 10), "call");

            s1.Add(new CTypeRef("LIST_ENTRY"), "first");
            s1.Add(t2, "b");

            Console.Write(new DefFactory().CreateMixedTypedef(s1, "ENTRY").Output("....", TAB));
        }
        static void Main(string[] args)
        {
            IDiaDataSource source = new DiaSource();
            IDiaSession session;
            source.loadDataFromPdb(@"F:\GuBigCollect\Tests_PDB\T08_AlgoPort1\Debug\T08_AlgoPort1.pdb");
            source.openSession(out session);

            IDiaSymbol global = session.globalScope;
            IDiaEnumSymbols enumSymbols;
            global.findChildren(SymTagEnum.SymTagUDT, "_Data2", 0, out enumSymbols);

            IDiaSymbol struct1 = enumSymbols.Item(0);
            struct1.findChildren(SymTagEnum.SymTagData, null, 0, out enumSymbols);

            IDiaSymbol member1 = enumSymbols.Item(0);

            Translator t = new Translator();
            CType t2 = t.TranslateStruct(struct1);

            Console.Write(new DefFactory().CreatePureDef((CBrace)t2, "X").Output(DOT, TAB));
            
        }
    }
}
