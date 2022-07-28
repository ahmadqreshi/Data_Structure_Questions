//graph is a non linear ds consist of nodes(vertices) and edges(arcs) connected to each other
//weighted graph - edges have some values
//unweighted graph - edges do not have values
//directed graph - edges are points to other nodes
//undirected graph - edges are not points to other nodes but are connected to each other

#include<bits/stdc++.h>
using namespace std;
//method 1 of storing Graph into memory by using array of list
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
}
//OUTPUT
/*
0-->1 2 
1-->0 4 
2-->0 3 4 
3-->2 4 
4-->2 3 1 
*/
