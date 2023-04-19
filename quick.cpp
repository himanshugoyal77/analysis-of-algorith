#include<stdio.h>
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int f(int *arr, int low, int high){
   int p = arr[low];
   int i = low;
   int j = high;

   while(i<j){
    while(i<=high-1 && arr[i] <= p){
        i++;
    }
    while(j>=low+1 && arr[j] > p){
        j--;
    }
    if(i<j){
        swap(arr[i], arr[j]);
    }
   }
   swap(arr[low], arr[j]);
    return j;
}

void quickSort(int *arr, int i, int j){
  if(i<j){
    int pivot= f(arr, i, j);
    quickSort(arr, i, pivot-1);
    quickSort(arr, pivot+1, j);
  }
}


 int main(){
   int n =10;
   int arr[n] = {10, 9, 8, 7, 98, 5, 4, 3, 2, 1};

   quickSort(arr, 0, n-1);

   for(int i=0; i<n; i++){
    cout<<arr[i]<<endl;
   }

 }
