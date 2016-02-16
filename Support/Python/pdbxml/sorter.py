from __future__ import print_function
import sys
from collections import deque
from toposort import toposort_flatten as topo_sort

# ref: https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm
class TarjanAlgo(object):
    def __init__(self, graph):
        self.stack = []
        self.index = 0
        self.graph = graph
        self.vertices = graph.vertices()
        self.props = {}
        for vertex in self.vertices:
            self.props[vertex] = TarjanVertex()
        self.indices = {}
        self.groups = []
        self.group_index = 0

    def solve(self):
        for vertex in self.vertices:
            if not self.props[vertex].touched:
                self.strong_connect(vertex)

    def strong_connect(self, vertex):
        self.props[vertex].init(self.index)
        self.index += 1
        self.stack.append(vertex)
        self.props[vertex].on_stack = True

        for next_vertex in self.graph.get_deps(vertex):
            if not self.props[next_vertex].touched:
                self.strong_connect(next_vertex)
                self.props[vertex].lowlink = min(
                    self.props[vertex].lowlink,
                    self.props[next_vertex].lowlink
                )
            elif self.props[next_vertex].on_stack:
                self.props[vertex].lowlink = min(
                    self.props[vertex].lowlink,
                    self.props[next_vertex].index
                )

        if self.props[vertex].lowlink == self.props[vertex].index:
            group = []
            while True:
                this_vertex = self.stack.pop()
                self.props[this_vertex].on_stack = False
                group.append(this_vertex)
                self.indices[this_vertex] = self.group_index
                if this_vertex == vertex:
                    break
            self.groups.append(group)
            self.group_index += 1

    def make_graph(self):
        graph = Graph()
        group_index = 0
        for group in self.groups:
            dep_indices = set()
            for vertex in group:
                for next_vertex in self.graph.get_deps(vertex):
                    next_group_index = self.indices[next_vertex]
                    dep_indices.add(next_group_index)
            graph.add(group_index, dep_indices)
            group_index += 1
        return graph


class TarjanVertex(object):
    def __init__(self):
        self.index = -1
        self.lowlink = -1
        self.on_stack = False

    @property
    def touched(self):
        return self.index >= 0

    def init(self, index):
        self.index = index
        self.lowlink = index


class Graph(object):
    def __init__(self):
        self.deps = {}

    def add(self, key, deps):
        self.deps[key] = deps

    def vertices(self):
        return self.deps.keys()

    def get_deps(self, key):
        return self.deps[key]


class TreeSorter(object):
    def __init__(self):
        self._info = {}

    def add(self, name, tree):
        self._info[name] = TreeVertex(tree, *tree.get_dep())

    def pre_sort(self):
        info = self._info
        is_internal = lambda name: name in info
        for v in info.values():
            v.dep = filter(is_internal, v.dep)
            v.use = filter(is_internal, v.use)

    def _make_scc(self):
        graph = TreeGraph(self._info)
        scc = TarjanAlgo(graph)
        scc.solve()
        return scc

    def _sort_scc(self, graph):
        # NOTE: is this step necessary?
        return topo_sort(graph.deps)

    def sort(self):
        result = []
        scc = self._make_scc()
        scc_graph = scc.make_graph()
        scc_order = self._sort_scc(scc_graph)
        for scc_index in scc_order:
            names = scc.groups[scc_index]
            if len(names) == 1:
                if scc_index in scc_graph.get_deps(scc_index):
                    self._info[names[0]].self_ref = True
                result.append(names)
            else:
                graph = Graph()
                for name in names:
                    graph.add(name,
                              set(filter(lambda u: scc.indices[u] == scc_index,
                                         self._info[name].use)))
                result.append(topo_sort(graph.deps))
        return result

    def get_type(self, name):
        return self._info[name].type

    def is_type_recursive(self, name):
        return self._info[name].self_ref

    def name_list(self):
        return self._info.keys()


class TreeVertex(object):

    def __init__(self, type, dep, use):
        self.type = type
        self.dep = dep
        self.use = use
        self.self_ref = False


class TreeGraph(object):

    def __init__(self, info):
        self._info = info

    def vertices(self):
        return self._info.keys()

    def get_deps(self, key):
        return self._info[key].dep
