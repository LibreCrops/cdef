using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.DiaExtra
{
    class ErrorCodes
    {
        public static int E_PDB_NOT_FOUND = unchecked((int)0x806D0005);
        public static int E_PDB_FORMAT = unchecked((int)0x806D000C);
        public static int REGDB_E_CLASSNOTREG = unchecked((int)0x80040154);
    }
}
