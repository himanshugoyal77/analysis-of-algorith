#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 10;
    int arr[n] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    for(int i=0; i<n; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }

    for(int i=0; i<n; i++){
    cout<<arr[i] << "-> ";
    }
    return 0;
}