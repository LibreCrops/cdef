using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PdbReader.DiaExtra
{
    enum CvCallEnum
    {
        NEAR_C = 0x00,
        NEAR_FAST = 0x04,
        NEAR_STD = 0x07,
        NEAR_SYS = 0x09,
        THISCALL = 0x0b,
        CLRCALL = 0x16
    }
}
