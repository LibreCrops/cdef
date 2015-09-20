using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;
using PdbReader.Types;

namespace PdbReader.Xml
{
    class XmlMaker
    {
        private XmlDocument _doc;
        private XmlElement _args, _unnamed, _named;
        private int _funcNum, _unnamedNum;

        public XmlMaker()
        {
            _doc = new XmlDocument();
            _doc.InsertBefore(
                _doc.CreateXmlDeclaration("1.0", "utf-8", null),
                _doc.DocumentElement);

            XmlElement root = _doc.CreateElement("defs");
            _doc.AppendChild(root);

            _args = _doc.CreateElement("args");
            root.AppendChild(_args);

            _unnamed = _doc.CreateElement("unnamed");
            root.AppendChild(_unnamed);

            _named = _doc.CreateElement("named");
            root.AppendChild(_named);

            _funcNum = 0;
            _unnamedNum = 0;

        }
        public void Save(System.IO.Stream stream)
        {
            _doc.Save(stream);
        }
        public void Save(string path)
        {
            _doc.Save(path);
        }


        private void AddAttr(XmlElement elem, string key, object val)
        {
            XmlAttribute attr = _doc.CreateAttribute(key);
            attr.Value = val.ToString();
            elem.Attributes.Append(attr);
        }

        private void AddChild(XmlElement elem, XmlElement child)
        {
            elem.AppendChild(child);
        }

        private XmlElement MakeElem(string tag)
        {
            return _doc.CreateElement(tag);
        }

        private static Dictionary<CPrim, string> _primNames = new Dictionary<CPrim, string>()
        {
            { PrimTypes.VOID,       "VOID" },

            { PrimTypes.WCHAR,      "WCHAR" },

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
        private static string EncodePrim(CPrim t)
        {
            return _primNames[t];
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
                return "$" + ((CTypeRef)type).Name;
            }
            else
            {
                return "#" + AddUnnamed((CBrace)type);
            }
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
            int curNum = ++_funcNum;
            XmlElement entry = MakeElem("func");
            AddAttr(entry, "id", curNum);
            foreach (CType argType in func.Args)
            {
                XmlElement arg = MakeElem("arg");
                AddTypeBasicAttrs(arg, argType, true);
                AddChild(entry, arg);
            }
            AddChild(_args, entry);
            return curNum;
        }

        private XmlElement MakeConstEntry(string name, int val)
        {
            XmlElement result = MakeElem(name);
            AddAttr(result, "name", name);
            AddAttr(result, "val", val);
            return result;
        }

        private void AddTypeBasicAttrs(XmlElement elem, CType type, bool writeWrap)
        {
            string a_attr, a_base, a_wrap;
            CTerm core, inner;

            core = UnwrapType(type, out a_wrap);
            inner = StripTypeAttr(core, out a_attr);
            a_base = EncodeBaseType(inner);

            if (a_attr != "") { AddAttr(elem, "attr", a_attr); }
            AddAttr(elem, "base", a_base);
            if (writeWrap) { AddAttr(elem, "wrap", a_wrap); }
        }

        private void AddNameAndOffsetAttrs(XmlElement elem, string name, Offset offset)
        {
            AddAttr(elem, "name", name);
            AddAttr(elem, "offset", OffsetStr(offset));
        }

        private XmlElement MakeFieldEntry(CType type, string name, Offset offset)
        {
            XmlElement result;
            if (type is CBits)
            {
                CBits bit = (CBits)type;
                result = MakeElem("bit-field");
                AddTypeBasicAttrs(result, bit.Next, false);
                AddNameAndOffsetAttrs(result, name, offset);
                AddAttr(result, "len", bit.Len);
            }
            else
            {
                result = MakeElem("field");
                AddTypeBasicAttrs(result, type, true);
                AddNameAndOffsetAttrs(result, name, offset);
            }
            return result;
        }

        private void AddGroup(XmlElement elem, CBrace type, string key, object val)
        {
            XmlElement group = MakeElem(type.Keyword);
            AddChild(elem, group);
            AddAttr(group, key, val);

            if (type is CEnum)
            {
                foreach (CEnum.Entry entry in ((CEnum)type).Entries)
                {
                    AddChild(group, MakeConstEntry(entry.Name, entry.Val));
                }
            }
            else
            {
                CTree tree = (CTree)type;
                foreach (CTree.Entry member in tree.Members)
                {
                    AddChild(group, MakeFieldEntry(member.Type, member.Name, member.Offset));
                }
            }
        }

        public int AddUnnamed(CBrace type)
        {
            int curNum = ++_unnamedNum;
            AddGroup(_unnamed, type, "id", curNum);
            return curNum;
        }

        public void AddNamed(CBrace type, string name)
        {
            AddGroup(_named, type, "name", name);
        }
    }
}
