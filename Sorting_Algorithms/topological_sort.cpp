#include<bits/stdc++.h>
using namespace std;

class DAG {
public:
    int V,E;
    vector<int> in_degree;
    vector<list<int>> adjList;
    DAG(int v, int e) {
        V=v;
        E=e;
        adjList.resize(v);
        in_degree.resize(v, 0);
    }
    void addEdge(int, int);
    void display();
};

void DAG::addEdge(int a, int b) {
    in_degree[b]++;
    adjList[a].push_back(b);
}

void DAG::display() {
    for(int i=0;i<V;i++) {
        printf("Adjacency list of %c: head",i+'A');
        for(auto x:adjList[i]) {
            printf(" -> %c",x+'A');
        }
        cout<<" -> null "<<endl;
    }
}

void topologicalSort(DAG g) {
    queue<int> Q;
    for(int i=0;i<g.V;i++) {
        if(g.in_degree[i]==0)
            Q.push(i);
    }
    while(!Q.empty()) {
        int v=Q.front();
        Q.pop();
        printf("%c ",v+'A');
        for(auto adjacent:g.adjList[v]) {
            g.in_degree[adjacent]--;
            if(g.in_degree[adjacent]==0)
                Q.push(adjacent);
        }
    }
}

int main() {
    int v,e;
    cout<<"Enter the number of vertices and edges = ";
    cin>>v>>e;
    DAG dag(v,e);
    cout<<"Enter the edge ="<<endl;
    for(int i=0;i<e;i++) {
        int a,b;
        cin>>a>>b;
        dag.addEdge(a,b);
    }
    cout<<"\nAdjacency List Representation = "<<endl;
    dag.display();
    cout<<"\nTopological Sort = ";
    topologicalSort(dag);
}