#!/usr/bin/env python3


"""
Copyright 2015 Gu Zhengxiong <rectigu@gmail.com>
"""


import sys
import traceback
import itertools
import os.path
from os import makedirs
from shutil import rmtree
from subprocess import check_output, SubprocessError

from future.utils import isidentifier


def main():
    dest = 'upper'
    try:
        rmtree(dest)
    except OSError:
        pass
    makedirs(dest, exist_ok=True)
    for pdb in sys.argv[1:]:
        names = get_output(pdb, 'list')
        names = sorted(set(names.splitlines()))
        structs = [
            i.split()[1] for i in names if i.startswith('STRUCT')
        ]
        enums = [
            i.split()[1] for i in names if i.startswith('ENUM')
        ]
        unions = [
            i.split()[1] for i in names if i.startswith('UNION')
        ]
        for i in itertools.chain(structs, enums, unions):
            if not i.isupper():
                continue
            if not isidentifier(i):
                continue
            defs = get_output(pdb, 'def', i)
            if not defs:
                continue
            print('writting {}...'.format(i))
            with open(os.path.join(dest, i) + '.h', 'w') as header:
                print(defs, file=header)


def get_output(pdb, cmd, *args):
    exe_path = r'\\VBOXSVR\novicelive\repo' \
               r'\PdbReader\PdbReader\bin\Release'
    exe = os.path.join(exe_path, 'PdbReader.exe')
    try:
        output = check_output(
            [exe, cmd, pdb, *args], universal_newlines=True
        )
    except SubprocessError:
        print('Error: {} {} {}'.format(cmd, pdb, args))
        traceback.print_exc()
        return b''
    return output


def group_by(iterable, key_func):
    """
    Wrap the itertools.groupby to make life easier.
    """
    groups = (
        list(sub)
        for key, sub in itertools.groupby(iterable, key_func)
    )
    return zip(groups, groups)


if __name__ == '__main__':
    main()
