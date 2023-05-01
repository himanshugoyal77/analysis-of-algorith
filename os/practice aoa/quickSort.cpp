#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int pivotElement(int * arr, int st, int end){
  int p=arr[st];
  int left = st;
  int right = end;

  while(left < right){
    while (left < end && arr[left] <= p){
        left++;
    }
    while (right > st && arr[right] > p){
        right--;
    }
    if(left < right){
        swap(arr[left], arr[right]);
    }
  }

   swap(arr[st], arr[right]);
//    cout<<right<<endl;
   return right;
}

void quickSort(int *arr, int st, int end){
   if(st<
   end){
       int pivot = pivotElement(arr, st, end);
    //    cout<<pivot<<endl;
       quickSort(arr, st, pivot);
       quickSort(arr, pivot+1, end);
   }
}

int main(){
    int n = 10;
    int arr[n] = {100, 9, 8, 70, 6, 5, 4, 3, 2, 123};
    int st = 0;
    int en = n-1;
    quickSort(arr, st, en);

    for(int i=0; i<n; i++){
    cout<<arr[i] << "-> ";
    }
    return 0;
}