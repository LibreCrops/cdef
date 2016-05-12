using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using Dia2Lib;
using PdbReader.DiaExtra;


namespace PdbReader
{
    class Pdb
    {
        private class PdbSymbolCollection : IEnumerable<PdbSymbol>
        {
            private Dictionary<string, List<PdbSymbol>> _symbols;
            public PdbSymbolCollection()
            {
                _symbols = new Dictionary<string, List<PdbSymbol>>();
            }
            public void Add(string name, PdbSymbol symbol)
            {
                List<PdbSymbol> symList;
                if (!_symbols.TryGetValue(name, out symList))
                {
                    symList = new List<PdbSymbol>();
                    _symbols.Add(name, symList);
                }
                symList.Add(symbol);
            }
            public PdbSymbol FindFirst(string name)
            {
                List<PdbSymbol> symList;
                if (_symbols.TryGetValue(name, out symList))
                {
                    return symList.First();
                }
                else
                {
                    return null;
                }
            }
            public IEnumerator<PdbSymbol> GetEnumerator()
            {
                return new PdbSymbolsEnumerator(_symbols.Values);
            }
            IEnumerator IEnumerable.GetEnumerator()
            {
                return GetEnumerator();
            }
        }

        private class PdbSymbolsEnumerator : IEnumerator<PdbSymbol>
        {
            IEnumerable<List<PdbSymbol>> _groups;
            IEnumerator<List<PdbSymbol>> _groupIter;
            IEnumerator<PdbSymbol> _itemIter;
            public PdbSymbolsEnumerator(IEnumerable<List<PdbSymbol>> groups)
            {
                _groups = groups;
                Reset();
            }
            public void Reset()
            {
                _groupIter = _groups.GetEnumerator();
                _itemIter = null;
            }
            public bool MoveNext()
            {
                if (_itemIter == null || _itemIter.MoveNext() == false)
                {
                    if (_groupIter.MoveNext())
                    {
                        _itemIter = _groupIter.Current.GetEnumerator();
                        _itemIter.MoveNext();
                        return true;
                    }
                    return false;
                }
                return true;
            }
            public PdbSymbol Current
            {
                get { return _itemIter.Current; }
            }
            object IEnumerator.Current
            {
                get { return Current; }
            }
            void IDisposable.Dispose() { }
        }

        private PdbSymbolCollection _symbols;
        protected Pdb()
        {
            _symbols = new PdbSymbolCollection();
        }

        private static IDiaSymbol LoadFile(string path)
        {
            IDiaSession session;
            IDiaSymbol global;
            try
            {
                IDiaDataSource source = new DiaSource();
                source.loadDataFromPdb(path);
                source.openSession(out session);
                global = session.globalScope;
            }
            catch (COMException ex)
            {
                if (ex.ErrorCode == ErrorCodes.E_PDB_FORMAT)
                {
                    throw new PdbFormatException();
                }
                else
                {
                    Console.WriteLine(ex.Message);
                    Environment.Exit(1);
                    throw new PdbNotFoundException();
                }
            }
            return global;
        }

        private void AddSymbol(IDiaSymbol symbol, PdbSymbolType type)
        {
            string name = PdbSymbol.GetInternName(symbol);
            _symbols.Add(name, new PdbSymbol(symbol, name, type));
        }

        private bool IsUdtEmpty(IDiaSymbol udt)
        {
            return udt.length == 0;
        }

        private void LoadUdts(IDiaSymbol global)
        {
            IDiaEnumSymbols symbols;
            global.findChildren(SymTagEnum.SymTagUDT, null, 0, out symbols);
            foreach (IDiaSymbol symbol in symbols)
            {
                if (!PdbSymbol.IsUnnamed(symbol) && !IsUdtEmpty(symbol))
                {
                    switch ((UdtKindEnum)symbol.udtKind)
                    {
                        case UdtKindEnum.UdtStruct:
                            AddSymbol(symbol, PdbSymbolTypes.Struct);
                            break;
                        case UdtKindEnum.UdtUnion:
                            AddSymbol(symbol, PdbSymbolTypes.Union);
                            break;
                    }
                }
            }
        }

        private void LoadEnums(IDiaSymbol global)
        {
            IDiaEnumSymbols symbols;
            global.findChildren(SymTagEnum.SymTagEnum, null, 0, out symbols);
            foreach (IDiaSymbol symbol in symbols)
            {
                if (!PdbSymbol.IsUnnamed(symbol))
                {
                    AddSymbol(symbol, PdbSymbolTypes.Enum);
                }
            }
        }

        public static Pdb Load(string path)
        {
            IDiaSymbol global = LoadFile(path);
            Pdb pdb = new Pdb();
            pdb.LoadUdts(global);
            pdb.LoadEnums(global);
            return pdb;
        }

        public IEnumerable<PdbSymbol> Symbols
        {
            get { return _symbols; }
        }
        public PdbSymbol Find(string name)
        {
            return _symbols.FindFirst(name);
        }
    }
}
