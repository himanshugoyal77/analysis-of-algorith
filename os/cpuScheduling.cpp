#include<iostream>
using namespace std;

struct process {
   int name;
   int arrival_time;
   int burst_time;
   int priority;
};

void cal(){


   for(int i=0; i<n; i++){
     c+=a[i].burst_time;
     completion[i] = c;
     tat_time[i] = completion[i] - a[i].arrival_time;
     wait_time[i] = tat_time[i] - a[i].burst_time;
     printf<<"%d\t\t%d\t\t"<<<<endl;
     at+=tat_time[i];
     wt+=wait_time[i];
   }

}

int main(){
   printf("")
   return 0;
}
