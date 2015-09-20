using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Dia2Lib;
using PdbReader.Collect;
using PdbReader.Types;
using PdbReader.Defs;
using PdbReader.Xml;

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
        static void TypesTest2()
        {
            SortedSet<TypeAttr> attrs = new SortedSet<TypeAttr>();
            // attrs.Add(TypeAttrs.Volatile);
            attrs.Add(TypeAttrs.Const);

            CStruct s1 = new CStruct();
            s1.Add(PrimTypes.INT, "a");
            s1.Add(PrimTypes.INT, "b");

            CType t1 = new CAttrTerm(s1, attrs);
            Console.WriteLine(t1.Define("v", "....", "    "));
        }
        static void Main(string[] args)
        {
            const string filePath = @"F:\ntkrnlmp.pdb";
            Pdb p1 = Pdb.Load(filePath);
            int count = 0;
            foreach (PdbSymbol sym in p1.Symbols)
            {
                Console.WriteLine(sym.Keyword + "\t" + sym.Name);
                if (++count == 10) { break; }
            }

            Environment.Exit(0);
            // Console.Write(new DefFactory().CreatePureDef((CBrace)t2, "X").Output(DOT, TAB));

            XmlMaker x = new XmlMaker();
            // x.AddNamed(t2, "PEB");
            // x.AddNamed(t.TranslateStruct(struct2), "DRIVER_OBJECT");
            // x.Save("F:\\a.xml");
        }
    }
}
