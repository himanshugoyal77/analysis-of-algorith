
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Item {
    int profit, weight;
    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
};

bool cmp(struct Item a, struct Item b){
   double r1 = (double)a.profit / (double)a.weight;
   double r2 = (double)b.profit / (double)b.weight;
   return r1 > r2;
}

double fractionalKnapsack(int W, struct Item a[], int N){
   sort(a, a+N, cmp);

   double finalVal = 0;

   for(int i=0; i<N; i++){
    if(a[i].weight <= W){
        finalVal += a[i].profit;
        W -= a[i].weight;
    }
    else{
        finalVal += a[i].profit * (double(W) / double(a[i].weight) );
        break;
    }
   }
   return finalVal;
}

int main (){
    int W = 50;
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << fractionalKnapsack(W, arr, N);
    return 0;
}
