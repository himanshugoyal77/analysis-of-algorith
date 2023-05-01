#include<iostream>
#include<bits/stdc++.h>
#define V 4
#define INF 99999
using namespace std;

void printSol(int graph[V][V]){
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if (graph[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << graph[i][j] << "   ";
        }
        cout<<"\n";
    }
}

void floydWarshall(int graph[V][V]){
    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
          for(int j=0; j<V; j++){
              if((graph[i][j] > graph[i][k] + graph[k][j])
              && graph[i][k] != INF && graph[k][j] != INF
              ){
                graph[i][j] = graph[i][k] + graph[k][j];
              }
           }
        }  
    }
    printSol(graph);
}

int main(){
    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };

    floydWarshall(graph);
    return 0;
}
