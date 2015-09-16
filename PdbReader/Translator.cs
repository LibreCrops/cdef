using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Dia2Lib;
using PdbReader.DiaExtra;
using PdbReader.Types;
using PdbReader.Collect;

namespace PdbReader
{
    class Translator
    {
        private bool _translatingTree;
        public CType Translate(IDiaSymbol sym)
        {
            switch ((SymTagEnum)sym.symTag)
            {
                case SymTagEnum.SymTagBaseType:
                    return TranslateBaseType(sym);

                case SymTagEnum.SymTagPointerType:
                    return TranslatePtr(sym);

                case SymTagEnum.SymTagArrayType:
                    return TranslateArr(sym);

                case SymTagEnum.SymTagFunctionType:
                    return TranslateFunc(sym);
                
                case SymTagEnum.SymTagUDT:
                    return TranslateUDT(sym);

                default:
                    return new CPrim("NotImpl");
            }
        }
        public CPrim TranslateBaseType(IDiaSymbol sym)
        {
            int size = (int)sym.length;
            switch ((BaseTypeEnum)sym.baseType)
            {
                case BaseTypeEnum.btVoid:
                    return PrimTypes.VOID;

                // no handler for btWChar
                // `wchar_t' will be compiled to ULONG

                case BaseTypeEnum.btInt:
                    return IntTypePairs.SelectBySize(size).Signed;
                case BaseTypeEnum.btUInt:
                    return IntTypePairs.SelectBySize(size).Unsigned;

                // the design logic of Dia2Lib is
                // eh.. MS guys must be brain fucked at that time.
                case BaseTypeEnum.btLong:
                    return PrimTypes.LONG;
                case BaseTypeEnum.btULong:
                    return PrimTypes.ULONG;

                default:
                    return new CPrim("NotImpl_BaseType");
            }
        }
        public CPtr TranslatePtr(IDiaSymbol sym)
        {
            CType next = Translate(sym.type);
            return new CPtr(next);
        }
        public CArr TranslateArr(IDiaSymbol sym)
        {
            CType next = Translate(sym.type);
            int len = (int)sym.count;           // it should be safe
            return new CArr(next, len);
        }
        public CFunc TranslateFunc(IDiaSymbol sym)
        {
            CType retType = Translate(sym.type);
            CFunc res = new CFunc(retType);

            IDiaEnumSymbols syms;
            sym.findChildren(SymTagEnum.SymTagFunctionArgType, null, 0, out syms);

            foreach (IDiaSymbol argSym in syms)
            {
                CType argType = Translate(argSym.type);
                res.Add(argType);
            }
            return res;
        }
        public CStruct TranslateStruct(IDiaSymbol sym)
        {
            IDiaEnumSymbols symbols;
            sym.findChildren(SymTagEnum.SymTagData, null, 0, out symbols);

            CStruct res = new CStruct();
            Offset lastOffset = Offset.Neg;
            foreach (IDiaSymbol subSym in symbols)
            {
                Offset thisOffset = Offset.FromDiaSymbol(subSym);
                if (thisOffset.IsLessThanOrEqualTo(lastOffset))
                {
                    symbols.Reset();
                    return TranslateStruct2(symbols);
                }

                string name = subSym.name;
                CType type = Translate(subSym.type);
                res.Add(type, name);
                lastOffset = thisOffset;
            }

            return res;
        }
        public CStruct TranslateStruct2(IDiaEnumSymbols symbols)
        {
            return new Collector(this).CollectStruct(symbols);
        }
        private string InternName(string name)
        {
            if (name.StartsWith("_"))
            {
                return name.Substring(1);
            }
            else
            {
                return name;
            }
        }
        public CType TranslateUDT(IDiaSymbol sym)
        {
            return new CTypeRef(InternName(sym.name));
        }
    }
}
