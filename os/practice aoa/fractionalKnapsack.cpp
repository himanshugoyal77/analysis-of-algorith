#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Item {
    int profit;
    int weight;
};

int fractionalKnapsack(int capacity, Item * arr, int N){
   int finalVal = 0;

   for(int i=0; i<N; i++){
    if(arr[i].weight < capacity){
        finalVal+=arr[i].profit;
        capacity-=arr[i].weight;
    }else{
        finalVal += arr[i].profit * (double(capacity) / double(arr[i].weight));
        break;
    }
   }
   return finalVal;
}

bool cmp(Item a, Item b){
   double r1 = double(a.profit) / double(a.weight);
   double r2 = double(b.profit) / double(b.weight);
   return r1 > r2;
}

int main (){
    int W = 50;
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int N = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr+N, cmp);
    cout << fractionalKnapsack( W, arr, N);
    
    return 0;
}