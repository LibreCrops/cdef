using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.Types
{
    interface IWrapVisitor
    {
        void VisitArr(CArr arr);
        void VisitPtr(CPtr ptr);
        void VisitFunc(CFunc func);
        void VisitBits(CBits bits);
    }
}
