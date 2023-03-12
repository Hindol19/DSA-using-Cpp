#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V, E;
    vector<list<int>> adjList;
public:
    Graph(int v, int e) {
        V=v;
        E=e;
        adjList.resize(v);
    }
    void addEdge(int, int);
    void display();
    void bfs(int);
};

void Graph::addEdge(int a, int b) {
    adjList[a].push_back(b);
    adjList[b].push_back(a);
}

void Graph::display() {
    for(int i=0;i<V;i++) {
        printf("Adjacency list of %c: head",i+'A');
        for(auto x:adjList[i]) {
            printf(" -> %c",x+'A');
        }
        cout<<" -> null "<<endl;
    }
}

void Graph::bfs(int v) { 
    vector<int> visited(V,0);
    queue<int> Q;
    visited[v]=1;
    Q.push(v);
    while(!Q.empty()) {
        v=Q.front();
        printf("%c ",v+'A');
        Q.pop();
        for(auto adjacent:adjList[v]) {
            if(visited[adjacent]==0) {
                visited[adjacent]=1;
                Q.push(adjacent);
            }
        }
    }
}

int main() {
    int v,e;
    cout<<"Enter the number of vertices and edges = ";
    cin>>v>>e;
    Graph g(v,e);
    cout<<"Enter the edge ="<<endl;
    for(int i=0;i<e;i++) {
        int a,b;
        cin>>a>>b;
        g.addEdge(a,b);
    }
    cout<<"Adjacency List Representation = "<<endl;
    g.display();
    cout<<"BFS Traversal = ";
    g.bfs(0);
}
