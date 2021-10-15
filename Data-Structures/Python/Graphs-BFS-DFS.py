class Graph:
    def __init__(self, v):
        self.V = v
        self.l = [[] for _ in range(self.V)]
        self.visited = [False for _ in range(self.V)]
    
    def addEdge(self, x, y):
        self.l[x].append(y)
        self.l[y].append(x)
    
    def printAdjlst(self):
        for i in range(self.V):
            print("Vertex " ,  i , "->", end='')
            for ele in self.l[i]:
                print(ele, ",", end='')

            
            print()
        
    
    def checked(self):
        for i in range(self.V):
            self.visited[i] = False
    
    def BFS(self, s):    
        queue = []
        self.visited[s] = True
        queue.append(s)
    
        while not len(queue)==0:
            s = queue[0]
            print(s, end=' ')
            queue.pop(0)
    
            for i in self.l[s]:
                if not self.visited[i]:
                    self.visited[i] = True
                    queue.append(i)
                
            
    
    def DFS(self, vertex):
        self.visited[vertex] = True
        adjList = self.l[vertex]

        print(vertex ,  end=" ")

        for i in self.l[vertex]:
            if not self.visited[i]:
                self.DFS(i)
    


if __name__ == '__main__':
    g = Graph(4)
    g.addEdge(0,1)
    g.printAdjlst()
    g.addEdge(0,2)
    g.printAdjlst()
    g.addEdge(2,3)
    g.printAdjlst()
    g.addEdge(1,2)
    g.printAdjlst()
    g.BFS(0)
    g.checked()
    print()
    g.DFS(1)
    g.checked()
    print()
    g.DFS(2)