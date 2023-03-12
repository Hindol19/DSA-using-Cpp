#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
        int v,e;
        cout<<"Enter the number of vertices and edges = ";
        cin>>v>>e;
        int adjMatrix[v][v] = {};
        cout<<"Enter the edge ="<<endl;
        for(int i=0;i<e;i++) {
                int a,b;
                cin>>a>>b;
                adjMatrix[a][b]=1;
                adjMatrix[b][a]=1;
        }
        cout<<"Adjacency Matrix = "<<endl;
        printf("   ");
        for(int i=0;i<v;i++) {
                printf("%-3c",i+'A');
        }
        cout<<endl;
        for(int i=0;i<v;i++) {
                printf("%-3c",i+'A');
                for(int j=0;j<v;j++) {
                        printf("%-3d",adjMatrix[i][j]);
                }
                cout<<endl;
        }
        
}