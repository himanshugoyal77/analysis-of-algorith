#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 10;
    int arr[n] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    for(int i=1; i<n; i++){
        for(int j=i; j>0; j--){
            if(arr[j] < arr[j-1]){
                swap(arr[j], arr[j-1]);
            }
            cout<<arr[j]<<endl;
        }
    }

    for(int i=0; i<n; i++){
    cout<<arr[i] << "-> ";
    }
    return 0;
}