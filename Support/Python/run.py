#!/usr/bin/env python3


import sys

from pdbxml.pdbxml import Session


s = Session()
for i in sys.argv[1:]:
    s.load(i)
    s.write_header()
