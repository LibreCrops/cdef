using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PdbReader.Types;

namespace PdbReader
{
    static class PrimTypes
    {
        public static CPrim VOID        = new CPrim("VOID");

        public static CPrim WCHAR       = new CPrim("WCHAR");

        public static CPrim CHAR        = new CPrim("CHAR");
        public static CPrim INT         = new CPrim("INT");
        public static CPrim SHORT       = new CPrim("SHORT");
        public static CPrim LONG        = new CPrim("LONG");
        public static CPrim LONGLONG    = new CPrim("LONGLONG");

        public static CPrim UCHAR       = new CPrim("UCHAR");
        public static CPrim UINT        = new CPrim("UINT");
        public static CPrim USHORT      = new CPrim("USHORT");
        public static CPrim ULONG       = new CPrim("ULONG");
        public static CPrim ULONGLONG   = new CPrim("ULONGLONG");

        public static CPrim FLOAT       = new CPrim("FLOAT");
        public static CPrim DOUBLE      = new CPrim("DOUBLE");
    }
}
