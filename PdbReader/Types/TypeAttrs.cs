using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    class TypeAttrs
    {
        public static TypeAttr Const = new TypeAttr("const", -2);
        public static TypeAttr Volatile = new TypeAttr("volatile", -1);
    }
}
