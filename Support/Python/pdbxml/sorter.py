from __future__ import print_function
import sys
from collections import deque
from toposort import toposort_flatten as topo_sort
from tarjan import find_sccs

# new name(of the FUNCTION): sort_structs

class TreeSorter(object):
    def __init__(self):
        self._self_refs = None
        self._types = dict()
        self._deps = dict()
        self._uses = dict()

    def add(self, name, struct):
        self._types[name] = struct
        self._deps[name], self._uses[name] = struct.get_dep()

    def pre_sort(self):
        struct_names = self._types.keys()
        is_internal = lambda name: name in struct_names
        for name in struct_names:
            self._deps[name] = filter(is_internal, self._deps[name])
            self._uses[name] = filter(is_internal, self._uses[name])

    def sort(self):
        structs_graph = self._deps
        
        sccs = find_sccs(structs_graph)

        # map vertex to its scc group index
        vertex_indices = {
            vertex : group_index
            for group_index, scc_group in enumerate(sccs)
            for vertex in scc_group
        }

        scc_graph = {
            index : {
                vertex_indices[next_vertex]
                for vertex in scc
                for next_vertex in structs_graph[vertex]
            }
            for index, scc in enumerate(sccs)
        }

        self._self_refs = {
            scc[0]
            for index, scc in enumerate(sccs)
            if len(scc) == 1 and (index in scc_graph[index])
        }
      
        result = [
            topo_sort({
                vertex : {
                    next_vertex
                    for next_vertex in self._uses[vertex]
                    if vertex_indices[next_vertex] == index
                }
                for vertex in sccs[index]
            })
            # NOTE: is topo_sort here necessary?
            for index in topo_sort(scc_graph)
        ]
        return result

    def get_type(self, name):
        return self._types[name]

    def is_type_recursive(self, name):
        return name in self._self_refs

    def name_list(self):
        return self._types.keys()
