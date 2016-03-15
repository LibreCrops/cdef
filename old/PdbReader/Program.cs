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
        static void Main(string[] args)
        {
            new App(args).Run();
        }
    }
}
