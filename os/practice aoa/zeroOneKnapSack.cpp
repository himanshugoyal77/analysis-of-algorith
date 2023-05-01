#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int helper(int n, int w, int* values, int* weights){
    if(n==0 || w==0) return 0;

    if(weights[n-1]<=w){
        int take = values[n-1] + helper(n-1, w-weights[n-1], values, weights);
        int notTake = 0 + helper(n-1, w, values, weights);

        return max(take, notTake);
    }else{
        return helper(n-1, w, values, weights);
    }
}

int main(){
   int W = 4;
   int N = 3;
   int values[] = {1,2,3};
   int weight[] = {4,5,6};
   int ans = 0;
   
   cout<<helper(N, W, values, weight);
   return ans;
}