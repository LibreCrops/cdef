using System;
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
                return 0;
            }
            _action = AppActions.LookUp(_args[0]);
            if (_action == null)
            {
                WriteError("unknown action: " + _args[0]);
                return 0;
            }
            if (_args.Length == 1)
            {
                WriteError("need file path");
                return 0;
            }
            try
            {
                _pdb = Pdb.Load(_args[1]);
            }
            catch (PdbNotFoundException)
            {
                WriteError("file not found: " + _args[1]);
                return 1;
            }
            catch (PdbFormatException)
            {
                WriteError("wrong pdb format");
                return 2;
            }

            try
            {
                _action.Execute(this);
            }
            catch (NotImplementedException ex)
            {
                WriteError("not impl: " + ex.Message);
                return 127;
            }
            return 0;
        }
    }
}
