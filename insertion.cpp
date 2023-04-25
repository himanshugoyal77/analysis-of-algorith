#include<stdio.h>
#include<iostream>
using namespace std;
#define n 10

 int main(){
  int arr[n] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  for(int i=0; i<n; i++){
    int j = i+1;
    while(j>0){
        if(arr[j]< arr[j-1]){
            swap(arr[j], arr[j-1]);
        }
        j--;
    }
  }

   for(int i=0; i<n; i++){
    cout<<arr[i]<<endl;
  }

 }
