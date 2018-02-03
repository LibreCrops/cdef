using System;
using System.Runtime.InteropServices;
using PdbReader.DiaExtra;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader
{
    class App
    {
        internal Pdb _pdb;
        internal AppAction _action;
        internal string[] _args;

        public App(string[] args)
        {
            _args = args;
        }

        private void MainHelp()
        {
            Console.Write(Resources.MainHelp);
        }

        public void WriteError(string msg)
        {
            Console.Error.WriteLine("PdbReader: " + msg);
        }

        public int Run()
        {
            if (_args.Length == 0)
            {
                MainHelp();
                return 1;
            }
            _action = AppActions.LookUp(_args[0]);
            if (_action == null)
            {
                WriteError("unknown action: " + _args[0]);
                return 1;
            }
            if (_args.Length == 1)
            {
                WriteError("need file path");
                return 1;
            }
            if (_args[0] == "def" && _args.Length <= 2)
            {
                WriteError("``def`` subcommand requires type names!");
                return 1;
            }
            try
            {
                _pdb = Pdb.Load(_args[1]);
            }
            catch (COMException ex)
            {
                if (ex.ErrorCode == ErrorCodes.REGDB_E_CLASSNOTREG)
                {
                    WriteError("DIA is not registered! You can register it with something like ``regsvr32 /path/to/msdia100.dll``.");
                }
                else if (ex.ErrorCode == ErrorCodes.E_PDB_FORMAT)
                {
                    WriteError("wrong pdb format: " + _args[1]);
                }
                else if (ex.ErrorCode == ErrorCodes.E_PDB_NOT_FOUND)
                {
                    WriteError("file not found: " + _args[1]);
                }
                else
                {
                    WriteError("COMException: " + ex.Message);
                    WriteError("ErrorCode: " + ex.ErrorCode.ToString("X"));
                }
                return 1;
            }

            try
            {
                _action.Execute(this);
            }
            catch (NotImplementedException ex)
            {
                WriteError("not impl: " + ex.Message + " @ " + _args[1]);
                return 127;
            }
            return 0;
        }
    }
}
