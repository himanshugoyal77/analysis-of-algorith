#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int st, int end, int mid){
    int left = st;
    int right = mid+1;
    vector<int> aux;

    while (left<=mid && right<=end)
    {
       if(arr[left] < arr[right]){
        aux.push_back(arr[left]);
        left++;
       }else{
         aux.push_back(arr[right]);
         right++;
       }
    }

    while(left<=mid){
         aux.push_back(arr[left]);
         left++;
    }

    while(right<=end){
         aux.push_back(arr[right]);
         right++;
    }

    for(int i=st; i<=end; i++){
        arr[i] = aux[i-st];
    }
}

void mergeSort(int *arr, int st, int end){
  if(st >= end) return;
  int mid = (st+end)/2;
  mergeSort(arr, st, mid);
  mergeSort(arr, mid+1, end);
  merge(arr, st, end, mid);
}

int main(){
    int n = 10;
    int arr[n] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int st = 0;
    int en = n-1;
    mergeSort(arr, st, en);

    for(int i=0; i<n; i++){
    cout<<arr[i] << "-> ";
    }
    return 0;
}