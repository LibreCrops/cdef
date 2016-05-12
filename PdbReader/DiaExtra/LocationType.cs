using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.DiaExtra
{
    enum LocationTypeEnum
    {
        LocIsNull,
        LocIsStatic,
        LocIsTLS,
        LocIsRegRel,
        LocIsThisRel,
        LocIsEnregistered,
        LocIsBitField,
        LocIsSlot,
        LocIsIlRel,
        LocInMetaData,
        LocIsConstant,
        LocTypeMax
    };
}
