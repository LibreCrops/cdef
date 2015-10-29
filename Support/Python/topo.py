from collections import deque

class Graph(object):
    def __init__(self):
        self.deps = {}
    
    def add(self, key, deps):
        self.deps[key] = deps
    
    def vertices(self):
        return self.deps.keys()
    
    def getDeps(self, key):
        return self.deps[key]

class TopoSorter(object):
    def __init__(self):
        self.backDeps = {}
        self.numDeps = {}
        self.starters = []

    def add(self, key, deps):
        numDeps = 0
        for dep in deps:
            if dep == key:
                continue
            numDeps += 1
            backDepArr = self.backDeps.get(dep)
            if not backDepArr:
                backDepArr = []
                self.backDeps[dep] = backDepArr
            backDepArr.append(key)
        self.numDeps[key] = numDeps
        if numDeps == 0:
            self.starters.append(key)

    def readGraph(self, graph):
        for vertex in graph.vertices():
            self.add(vertex, graph.getDeps(vertex))
    
    def sort(self):
        order = []
        backDeps = self.backDeps
        numDeps = self.numDeps
        numProcessed = 0
        numVertices = len(numDeps)
        queue = deque(self.starters)
        while queue:
            vertex = queue.popleft()
            numProcessed += 1
            order.append(vertex)
            for nextVertex in (backDeps.get(vertex) or []):
                numDeps[nextVertex] -= 1
                if numDeps[nextVertex] == 0:
                    queue.append(nextVertex)
        assert numProcessed == numVertices, 'not DAG'
        return order

class TarjanVertex(object):
    def __init__(self):
        self.index = -1
        self.lowlink = -1
        self.onStack = False
    
    @property
    def touched(self):
        return self.index >= 0
    
    def init(self, index):
        self.index = index
        self.lowlink = index

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
        self.groupIndex = 0
    
    def solve(self):
        for vertex in self.vertices:
            if not self.props[vertex].touched:
                self.strongConnect(vertex)
    
    def strongConnect(self, vertex):
        self.props[vertex].init(self.index)
        self.index += 1
        self.stack.append(vertex)
        self.props[vertex].onStack = True
        
        for nextVertex in self.graph.getDeps(vertex):
            if not self.props[nextVertex].touched:
                self.strongConnect(nextVertex)
                self.props[vertex].lowlink = min(
                    self.props[vertex].lowlink,
                    self.props[nextVertex].lowlink
                )
            elif self.props[nextVertex].onStack:
                self.props[vertex].lowlink = min(
                    self.props[vertex].lowlink,
                    self.props[nextVertex].index
                )
        
        if self.props[vertex].lowlink == self.props[vertex].index:
            group = []
            while True:
                thisVertex = self.stack.pop()
                self.props[thisVertex].onStack = False
                group.append(thisVertex)
                self.indices[thisVertex] = self.groupIndex
                if thisVertex == vertex:
                    break
            self.groups.append(group)
            self.groupIndex += 1

    def makeGraph(self):
        graph = Graph()
        groupIndex = 0
        for group in self.groups:
            depIndices = set()
            for vertex in group:
                for nextVertex in self.graph.getDeps(vertex):
                    nextGroupIndex = self.indices[nextVertex]
                    depIndices.add(nextGroupIndex)
            graph.add(groupIndex, list(depIndices))
            groupIndex += 1
        return graph

class Dummy(object):
    def __init__(self, s):
        self.name = s
    
    def __str__(self):
        return self.name

a = Dummy('a')
b = Dummy('b')
c = Dummy('c')
d = Dummy('d')
e = Dummy('e')
f = Dummy('f')
g = Dummy('g')
h = Dummy('h')

gr = Graph()
gr.add(a, [b])
gr.add(b, [c])
gr.add(c, [a])
gr.add(d, [b, c, e])
gr.add(e, [d, f])
gr.add(f, [c, g])
gr.add(g, [f])
gr.add(h, [e, g, h]) # try remove the 2nd `h' here
                      # for us, it important to be able to detect singleton with self-reference
ta = TarjanAlgo(gr)
ta.solve()
i = 0
for group in ta.groups:
    print 'Group', i, ':',
    for v in group:
        print v,
    print

print
for v in [a,b,c,d,e,f,g,h]:
    print v, ':', ta.indices[v]

print
gg = ta.makeGraph()
st = TopoSorter()
st.readGraph(gg)
for v in st.sort():
    print v
