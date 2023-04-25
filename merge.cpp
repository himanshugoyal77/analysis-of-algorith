#include<stdio.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void merg(int *arr, int n, int st, int en, int mid){
   int left = st;
   int right = mid+1;
   vector<int> aux;
   int k=0;

   while(left <=mid && right <= en){
     if(arr[left] < arr[right]){
        aux.push_back(arr[left]);

        left++;
     }
     else{
        aux.push_back(arr[right]);
        right++;
     }
   }

   while(left <= mid){
    aux.push_back(arr[left]);
    left++;
   }

   while(right <= en){
    aux.push_back(arr[right]);
    right++;
   }

  for(int i=st; i<en+1; i++){
    arr[i] = aux[i- st];
  }

}


void mergeSort(int *arr, int n, int st, int en){
    if(st >= en) return;
    int mid = (st + en)/2;
    mergeSort(arr, n, st, mid);
    mergeSort(arr, n, mid+1, en);

    merg(arr, n, st, en, mid);
}

int main(){
  int n = 10;
  int arr[n] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int st = 0;
  int en = n-1;

  mergeSort(arr, n, st, en);

  for(int i=0; i<n; i++){
    cout<<arr[i]<<endl;
  }

  return 0;

 }
