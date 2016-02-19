from functools import reduce

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

# [TODO] consider graph `normalize'
# ref: https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm
class TarjanAlgorithm(object):
    def __init__(self, graph):
        self.stack = []
        self.index = 0
        self.graph = graph
        self.vertices = graph.keys()
        self.props = {}
        for vertex in self.vertices:
            self.props[vertex] = TarjanVertex()
        self.groups = []

    def solve(self):
        for vertex in self.vertices:
            if not self.props[vertex].touched:
                self.strong_connect(vertex)

    def strong_connect(self, vertex):
        self.props[vertex].init(self.index)
        self.index += 1
        self.stack.append(vertex)
        self.props[vertex].on_stack = True

        for next_vertex in self.graph[vertex]:
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
                if this_vertex == vertex:
                    break
            self.groups.append(group)

def find_sccs(graph):
    algorithm = TarjanAlgorithm(graph)
    algorithm.solve()
    return algorithm.groups
