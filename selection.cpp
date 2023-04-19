#include<stdio.h>
#include<iostream>
using namespace std;
#define n 10

 int main(){
  int arr[n] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

for(int i=0; i<n; i++){
   int min_idx= i;

   for(int j=i+1; j<n; j++){
    if(arr[min_idx] > arr[j]){
        min_idx = j;
    }
   }

   swap(arr[i], arr[min_idx]);
}

   for(int i=0; i<n; i++){
    cout<<arr[i]<<endl;
  }

 }
