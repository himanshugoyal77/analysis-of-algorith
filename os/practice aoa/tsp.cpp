#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v 4

int tsp(int graph[][v], int s){
    vector<int> vertex;
    int min_path = INT_MAX;

    for(int i=0; i<v; i++){
        if(i != s) vertex.push_back(i);
    }

    do{
       int curr_weight = 0;
       int k = s;
       for(int i=0; i<v; i++){
        curr_weight += graph[k][vertex[i]];
        k = vertex[i];
       }
       curr_weight+=graph[k][s];
       min_path = min(min_path, curr_weight);
    }while (next_permutation(vertex.begin(), vertex.end()));

   return min_path;
    
}

int main(){
    int graph[][v] = {{0, 10, 15, 20}, 
                        {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
    int source = 0;
    cout<< tsp(graph, source);
    return 0;
}