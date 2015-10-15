using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    class CallConvs
    {
        public static CallConv Default  = new CallConv(null);
        public static CallConv Cdecl    = new CallConv("__cdecl");
        public static CallConv Stdcall  = new CallConv("__stdcall");
    }
}
