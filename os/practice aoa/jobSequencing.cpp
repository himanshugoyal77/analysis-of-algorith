#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Job {
  char id;
  int deadLine;
  int profit;
};

bool cmp (Job a, Job b){
   return a.profit > b.profit;
}

void printJobScheduling(struct Job a[], int N){
   sort(a, a+N, cmp);

   int res[N];
   bool available[N];

   for(int i=0; i<N; i++){
    available[i] = false;
   }

   for(int i=0; i<N; i++){
    for(int j=min(a[i].deadLine, N); j>=0; j--){
        if(available[j] == false){
            //res[i] = i;
            available[i] = true;
            break;
        }
    }
   }

   for(int i=0; i<N; i++){
    if(available[i]){
        cout<<a[i].id<<endl;
    }
   }
}


int main()
{
  Job arr[] = { { 'a', 2, 100 },
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 3, 15 } };

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs "
            "\n";

    // Function call
    printJobScheduling(arr, n);
    return 0;
}
