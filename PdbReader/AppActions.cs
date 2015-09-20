using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader
{
    class AppActions
    {
        private static Dictionary<string, AppAction> _actions =
            new Dictionary<string, AppAction>()
            {
                { "list",   new AppAction.Action_List() },
                { "xml",    new AppAction.Action_Xml() },
                { "def",    new AppAction.Action_Def() },
            };

        public static AppAction LookUp(string name)
        {
            AppAction result;
            _actions.TryGetValue(name, out result);
            return result;
        }
    }
}
