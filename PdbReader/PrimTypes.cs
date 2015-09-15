using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PdbReader.Types;

namespace PdbReader
{
    static class PrimTypes
    {
        public static CPrim VOID        = new CPrim("void");

        public static CPrim CHAR        = new CPrim("char");
        public static CPrim INT         = new CPrim("int");
        public static CPrim SHORT       = new CPrim("short");
        public static CPrim LONG        = new CPrim("long");
        public static CPrim LONGLONG    = new CPrim("__int64");

        public static CPrim UCHAR       = new CPrim("unsigned char");
        public static CPrim UINT        = new CPrim("unsigned int");
        public static CPrim USHORT      = new CPrim("unsigned short");
        public static CPrim ULONG       = new CPrim("unsigned long");
        public static CPrim ULONGLONG   = new CPrim("unsigned __int64");
    }
}
