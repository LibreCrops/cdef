import sys

from .ctype import CTree
from .xmlparser import parse_xml
from .sorter import sort_structs
from .definer import Definer, BraceDefMaker
from .primtypes import setup_goo_matcher

class Session(object):
    def __init__(self):
        self._data = {}

    def _add_data(self, file_path, name, type):
        self._data[name] = type

    def _split_data(self):
        structs = []
        enums = []
        for name, impl in self._data.iteritems():
            brace = impl
            if isinstance(brace, CTree):
                structs.append((name, brace))
            else:
                enums.append((name,brace))
        return structs, enums

    def load(self, file_path):
        name_type_pairs = parse_xml(file_path)
        for name, type in name_type_pairs:
            self._add_data(file_path, name, type)

    def write_header(self, file_handle = sys.stdout):
        structs_list, enum_list = self._split_data()
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
