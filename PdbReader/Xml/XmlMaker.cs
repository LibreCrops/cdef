using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PdbReader.Types;

namespace PdbReader.Xml
{
    class XmlMaker
    {
        private static Dictionary<CPrim, string> _primNames = new Dictionary<CPrim, string>()
        {
            { PrimTypes.VOID,       "VOID" },

            { PrimTypes.CHAR,       "CHAR" },
            { PrimTypes.UCHAR,      "UCHAR" },
            { PrimTypes.SHORT,      "SHORT" },
            { PrimTypes.USHORT,     "USHORT" },
            { PrimTypes.INT,        "INT" },
            { PrimTypes.UINT,       "UINT" },
            { PrimTypes.LONG,       "LONG" },
            { PrimTypes.ULONG,      "ULONG" },

            { PrimTypes.LONGLONG,   "LONGLONG" },
            { PrimTypes.ULONGLONG,  "ULONGLONG" },

            { PrimTypes.FLOAT,      "FLOAT" },
            { PrimTypes.DOUBLE,     "DOUBLE" },
        };
        private string EncodePrim(CPrim t)
        {
            return _primNames[t];
        }

        private int _funcNum;
        private int _unnamedNum;
        private PartXmlWriter _argsWriter;
        private PartXmlWriter _unnamedWriter;
        private PartXmlWriter _namedWriter;

        public XmlMaker()
        {
            _funcNum = 0;
            _unnamedNum = 0;
            _argsWriter = new PartXmlWriter();
            _unnamedWriter = new PartXmlWriter();
            _namedWriter = new PartXmlWriter();
        }

        private string OffsetStr(Offset offset)
        {
            if (offset.Bits == 0)
            {
                return offset.Bytes + "";
            }
            else
            {
                return offset.Bytes.ToString() + "." + offset.Bits.ToString();
            }
        }

        internal int AddFunc(CFunc func)
        {
            _funcNum++;
            _argsWriter.BeginElem("func");
            _argsWriter.AddAttr("id", _funcNum + "");
            foreach (CType argType in func.Args)
            {
                // !! reuse code below
            }
            _argsWriter.EndElem();
            return _funcNum;
        }

        public void WriteField(CTree.Entry field)
        {
            PartXmlWriter w = new PartXmlWriter();
            CType t = field.Type;
            CTerm core;
            AttrWrapMaker maker = new AttrWrapMaker();
            t.UnwrapTo(maker, out core);

            string tag = maker.HasBitField ? "bit-field" : "field";
            w.BeginElem(tag);

            CTerm baseType;
            if (core is CAttrTerm)
            {
                CAttrTerm attrTerm = ((CAttrTerm)core);
                w.AddAttr("attr", attrTerm.AttrStr);
                baseType = attrTerm.CoreType;
            }
            else
            {
                baseType = core;
            }

            string a_base;
            if (core is CPrim)
            {
                a_base = "." + EncodePrim((CPrim)core);
            }
            else if (core is CTypeRef)
            {
                a_base = ((CTypeRef)core).Name;
            }
            else
            {
                a_base = "__Brace__";
            }
            w.AddAttr("base", a_base);
            if (!maker.HasBitField)
            {
                w.AddAttr("wrap", maker.Value);
            }
            w.AddAttr("name", field.Name);
            w.AddAttr("offset", OffsetStr(field.Offset));
            if (maker.HasBitField)
            {
                w.AddAttr("len", maker.BitFieldLen.ToString());
            }

            w.EndElem();
            Console.WriteLine(w.Text);
        }
    }
}
