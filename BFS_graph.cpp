/*
GRAPH TRAVERSAL
1) BFS - Breadth first search :- iterative algorithm to cover each node in the Graph
2) DFS - depth first search : recursive algorithm to cover each node in the graph

Both traversing algorithm has linear time complexity O(V+E)
*/
#include<bits/stdc++.h>
using namespace std;
class Graph {
    int V;
    list<int> *l;//we take pointer beacuse it points to array of doubly linked list
    public:
    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int i,int j, bool undirected = true) {
        l[i].push_back(j);
        if(undirected) {
            l[j].push_back(i);
        }
    }
    void printAdjList() {
        for(int i=0;i<V;i++) {
            cout<<i<<"-->";
            for(auto node : l[i]) {
                cout<<node<<" ";
            }
            cout<<endl;
        }
    }
    void BFS(int source) {
        queue<int> q;
        bool *visited = new bool[V]{false}; //we take pointer beacuse it points to array
        q.push(source);
        visited[source] = true;
        while(!q.empty()) {
            int f = q.front();
            cout<<f<<" ";
            q.pop();
            for(int nbrs : l[f]) {
                if(!visited[nbrs]) {
                    q.push(nbrs);
                    visited[nbrs] = true;
                }
            }
        }
    }
};
int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,1);
    
    g.printAdjList();
    cout<<endl;
    g.BFS(0);
}
//OUTPUT
/*
0-->1 2 
1-->0 4 
2-->0 3 4 
3-->2 4 
4-->2 3 1 
BFS :
0 1 2 4 3
*/
