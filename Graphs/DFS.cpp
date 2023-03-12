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
    void dfs(int);
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
        cout<<endl;
    }
}

void Graph::dfs(int v) { 
    int visited[V]={};
    stack<int> S;
    visited[v]=1;
    S.push(v);
    while(!S.empty()) {
        v=S.top();
        printf("%c ",v+'A');
        S.pop();
        for(auto adjacent:adjList[v]) {
            if(visited[adjacent]==0) {
                visited[adjacent]=1;
                S.push(adjacent);
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
    cout<<"DFS Traversal = ";
    g.dfs(0);
}
