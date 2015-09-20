using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using PdbReader.Defs;
using PdbReader.Xml;

namespace PdbReader
{
    abstract class AppAction
    {
        public abstract void Execute(App app);

        public class Action_List : AppAction
        {
            public override void Execute(App app)
            {
                foreach (PdbSymbol symbol in app._pdb.Symbols)
                {
                    Console.WriteLine(symbol.Keyword + "\t" + symbol.Name);
                }
            }
        }
        public class Action_Xml : AppAction
        {
            public override void Execute(App app)
            {
                XmlMaker maker = new XmlMaker();
                Translator translator = new Translator();
                foreach (PdbSymbol symbol in app._pdb.Symbols)
                {
                    maker.AddNamed(symbol.TranslateBy(translator), symbol.Name);
                }
                maker.Save(Console.OpenStandardOutput());
            }
        }
        public class Action_Def : AppAction
        {
            public override void Execute(App app)
            {
                DefFactory factory = new DefFactory();
                Translator translator = new Translator();
                Pdb pdb = app._pdb;
                string[] args = app._args;
                for (int i = 2; i < args.Length; i++)
                {
                    string symName = PdbSymbol.InternName(args[i]);
                    PdbSymbol symbol = pdb.Find(symName);
                    if (symbol == null)
                    {
                        app.WriteError("can't find symbol: " + symName);
                        continue;
                    }
                    Def def = factory.CreateMixedTypedef(symbol.TranslateBy(translator), symbol.Name);
                    Console.WriteLine(def.Output("", "    "));
                }
            }
        }
    }
}
