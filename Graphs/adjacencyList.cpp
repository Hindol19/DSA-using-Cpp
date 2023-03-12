#include <bits/stdc++.h>
using namespace std;

int main() {
    int v,e;
    cout<<"Enter the number of vertices and edges = ";
    cin>>v>>e;
     vector<list<int>> adjList(v);
    cout<<"Enter the edge ="<<endl;
    for(int i=0;i<e;i++) {
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    for(int i=0;i<v;i++) {
        printf("Adjacency list of %c: head",i+'A');
        for(auto x:adjList[i]) {
            printf(" -> %c",x+'A');
        }
        cout<<" -> null "<<endl;
    }
}