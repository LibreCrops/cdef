using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
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

        private CTerm UnwrapType(CType type, out string wrap)
        {
            CTerm core;
            if (type is CWrap)
            {
                AttrWrapMaker maker = new AttrWrapMaker(this);
                type.UnwrapTo(maker, out core);
                wrap = maker.Value;
            }
            else
            {
                core = (CTerm)type;
                wrap = "";
            }
            return core;
        }

        private CTerm StripTypeAttr(CTerm core, out string attr)
        {
            CTerm inner;
            if (core is CAttrTerm)
            {
                CAttrTerm attrTerm = (CAttrTerm)core;
                inner = attrTerm.CoreType;
                attr = attrTerm.AttrStr;
            }
            else
            {
                inner = core;
                attr = "";
            }
            return inner;
        }

        private string EncodeBaseType(CTerm type)
        {
            if (type is CPrim)
            {
                return "." + EncodePrim((CPrim)type);
            }
            else if (type is CTypeRef)
            {
                return ((CTypeRef)type).Name;
            }
            else
            {
                return "__Brace__";
            }
        }

        // basic attrs: `attrs'(optional), `base', `wrap'
        private void WriteTypeBasicAttrs(PartXmlWriter writer, CType type, bool writeWrap)
        {
            string a_attr, a_base, a_wrap;
            CTerm core, inner;

            core = UnwrapType(type, out a_wrap);
            inner = StripTypeAttr(core, out a_attr);
            a_base = EncodeBaseType(inner);

            if (a_attr != "") { writer.AddAttr("attr", a_attr); }
            writer.AddAttr("base", a_base);
            if (writeWrap) { writer.AddAttr("wrap", a_wrap); }
        }

        private void WriteNameAndOffset(PartXmlWriter writer, CTree.Entry field)
        {
            writer.AddAttr("name", field.Name);
            writer.AddAttr("offset", OffsetStr(field.Offset));
        }

        internal int AddFunc(CFunc func)
        {
            _funcNum++;
            _argsWriter.BeginElem("func");
            _argsWriter.AddAttr("id", _funcNum + "");
            foreach (CType argType in func.Args)
            {
                _argsWriter.BeginElem("arg");
                WriteTypeBasicAttrs(_argsWriter, argType, true);
                _argsWriter.EndElem();
            }
            _argsWriter.EndElem();
            return _funcNum;
        }

        internal void WriteField(PartXmlWriter writer, CTree.Entry field)
        {
            CType type = field.Type;
            if (type is CBits)
            {
                CBits bit = (CBits)type;
                writer.BeginElem("bit-field");
                WriteTypeBasicAttrs(writer, bit.Next, false);
                WriteNameAndOffset(writer, field);
                writer.AddAttr("len", bit.Len + "");
            }
            else
            {
                writer.BeginElem("field");
                WriteTypeBasicAttrs(writer, type, true);
                WriteNameAndOffset(writer, field);
            }
            writer.EndElem();
        }

        private void AddBrace(PartXmlWriter writer, CBrace type, string key, string val)
        {
            writer.BeginElem(type.Keyword);
            writer.AddAttr(key, val);
            if (type is CEnum)
            {
                foreach (CEnum.Entry entry in ((CEnum)type).Entries)
                {
                    writer.BeginElem("const");
                    writer.AddAttr("name", entry.Name);
                    writer.AddAttr("val", entry.Val + "");
                    writer.EndElem();
                }
            }
            else
            {
                CTree tree = (CTree)type;
                foreach (CTree.Entry member in tree.Members)
                {
                    WriteField(writer, member);
                }
            }
            writer.EndElem();
        }

        public void AddUnnamed(CBrace type)
        {
            _unnamedNum++;
            AddBrace(_unnamedWriter, type, "id", _unnamedNum + "");
        }

        public void AddNamed(CBrace type, string name)
        {
            AddBrace(_namedWriter, type, "name", name);
        }

        private void AppendResult(StreamWriter sw, string s)
        {
            sw.Write(s);
        }

        private void AppendResultGroup(StreamWriter sw, string tag, PartXmlWriter writer)
        {
            AppendResult(sw, "<" + tag + ">");
            AppendResult(sw, writer.Text);
            AppendResult(sw, "</" + tag + ">");
        }

        public void WriteResultTo(Stream output)
        {
            using (StreamWriter sw = new StreamWriter(output))
            {
                AppendResult(sw, "<?xml version=\"1.0\" ?>");
                AppendResult(sw, "<defs>");
                AppendResultGroup(sw, "args", _argsWriter);
                AppendResultGroup(sw, "unnamed", _unnamedWriter);
                AppendResultGroup(sw, "named", _namedWriter);
                AppendResult(sw, "</defs>");
            }
        }
    }
}
