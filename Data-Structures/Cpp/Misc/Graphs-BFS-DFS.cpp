#include <iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    bool *visited; 
public:
    Graph(int V){
        this->V = V;
        l=new list <int>[V]; 
        visited = new bool[V];
    }
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printAdjlst(){
        for (int i = 0; i < V ;i++){
            cout<<"Vertex " << i <<"->";
            for (int ele: l[i]){
                cout<< ele<<",";

            }
            cout<<endl;
        }
    }
    void checked(){
        for(int i = 0 i < V i++)
            visited[i] = false
    }
    void  BFS(int s)  {
        list<int> queue;
        visited[s] = true;
        queue.push_back(s);
        list<int>::iterator i;
        while(!queue.empty()){
            s = queue.front();
            cout << s << " ";
            queue.pop_front();
    
            for (i = l[s].begin(); i != l[s].end(); ++i)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
    }}
    void DFS(int vertex) {
    visited[vertex] = true;
    list<int> adjList = l[vertex];

    cout << vertex << " ";

    list<int>::iterator i;
    for ( i = adjList.begin(); i != adjList.end(); ++i)
        if (!visited[*i])
        DFS(*i);
    }
};

int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.printAdjlst();
    g.addEdge(0,2);
    g.printAdjlst();
    g.addEdge(2,3);
    g.printAdjlst();
    g.addEdge(1,2);
    g.printAdjlst();
    g.BFS(0);
    g.checked();
    cout<<endl;
    g.DFS(1);
    g.checked();
    g.DFS(2);
    return 0;
}
