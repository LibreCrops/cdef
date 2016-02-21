import sys

from .ctype import CTree
from .xmlparser import XmlParser
from .sorter import sort_structs
from .definer import Definer, BraceDefMaker
from .primtypes import setup_goo_matcher

class Session(object):
    def __init__(self):
        self._storage = Storage()
        self._file_index = 0

    def load(self, file_path):
        parser = XmlParser(file_path)
        self._storage.begin_file(self._file_index)
        parser.read_to_storage(self._storage)
        self._storage.end_file()
        self._file_index += 1

    def write_header(self, file_handle = sys.stdout):
        structs_list, enum_list = self._storage.split()
        structs_dict = dict(structs_list)
        struct_groups, recursive_types = sort_structs(structs_list)
        
        definer = Definer()
        setup_goo_matcher(definer.matcher)
        definer.matcher.tree_names_list = structs_dict.keys()
        separator = ('/' * 79) + '\n'
        file_handle.write(separator)
        
        for name, type in enum_list:
            file_handle.write(BraceDefMaker(name, type, definer).mixed_def())
            file_handle.write('\n')
        file_handle.write(separator)
        
        for group in struct_groups:
            if len(group) == 1 and group[0] not in recursive_types:
                name = group[0]
                type = structs_dict[name]
                file_handle.write(BraceDefMaker(name, type, definer).mixed_def())
                file_handle.write('\n')
            else:
                makers = [
                    BraceDefMaker(name, structs_dict[name], definer)
                    for name in group]
                for maker in makers:
                    file_handle.write(maker.typedef())
                file_handle.write('\n')
                for maker in makers:
                    file_handle.write(maker.pure_def())
                file_handle.write('\n')

    def write_header_to_file(self, file_path):
        f = open(file_path, 'w')
        self.write_header(f)
        f.close()


class Storage(object):
    def __init__(self):
        self._data = {}

    def begin_file(self, file):
        self._file = file
        self._indices = {}

    def end_file(self):
        self._file = None
        self._indices = None

    def _fetch_index(self, name):
        index = self._indices.get(name)
        index = index + 1 if (index is not None) else 0
        self._indices[name] = index
        return index

    def add(self, name, type):
        file = self._file
        index = self._fetch_index(name)
        items = self._data.get(name)
        if not items:
            items = []
            self._data[name] = items
        items.append(ImplItem(type, file, index))

    @property
    def impls(self):
        return self._data

    def split(self):
        structs = []
        enums = []
        for name, impls in self._data.items():
            brace = impls[0].type
            if isinstance(brace, CTree):
                structs.append((name, brace))
            else:
                enums.append((name,brace))
        return structs, enums

class ImplItem(object):
    def __init__(self, type, file, index):
        self.type = type
        self.file = file
        self.index = index
