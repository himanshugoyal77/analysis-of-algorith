#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;
};

int findParent(int * parent, int vertex){
     if(parent[vertex] == vertex) return vertex;
     return findParent(parent, parent[vertex]);
}

bool cmp(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

void kruskals(Edge *input, int e, int n){
    sort(input, input+e, cmp);

    Edge output[n-1];
    int parent[n];

    for(int i=0; i<n; i++){
        parent[i] = i;
    }

    int i=0;
    int count = 0;

    while(count != n-1){
        Edge currentEdge = input[i];
        int sourceParent = findParent(parent, currentEdge.source);
        int descParent = findParent(parent, currentEdge.destination);
        
        if(sourceParent != descParent){
            output[count]=currentEdge;
            count++;
            parent[sourceParent] = descParent;
        }     
        i++;
    }

    for(int i=0; i<n; i++){
        if(output[i].source < output[i].destination){
            cout<<output[i].source << "-> "<<output[i].destination << " " << output[i].weight << endl;
        }else{
            cout<<output[i].destination << "-> "<<output[i].source << " " << output[i].weight << endl;
        }
    }
}

int main(){
    cout<<"Hello";
    int n, e;
    cin>>n>>e;
    Edge input[e];

    for(int i=0; i<e; i++){
        int s, d, w;
        cin>>s>>d>>w;
        input[i].source =s;
        input[i].destination =d;
        input[i].weight =w;
    }

    kruskals(input, e, n);
    return 0;
}