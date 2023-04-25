

struct process {
   int name;
   int arrival_time;
   int burst_time;
   int priority;
};

void cal(struct process a[],int n){
   printf("process \tburst_time \tturanaround \twait \n");
   int tat_time[n], wait_time[n], at=0, wt=0, c=0, completion[n];

   for(int i=0; i<n; i++){
     c+=a[i].burst_time;
     completion[i] = c;
     tat_time[i] = completion[i] - a[i].arrival_time;
     wait_time[i] = tat_time[i] - a[i].burst_time;
     printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, a[i].burst_time, tat_time[i], wait_time[i]);
     at+=tat_time[i];
     wt+=wait_time[i];
   }

   printf("avg tat = %d", at/n);
   printf("avg wt = %d", wt/n);

}

int main(){
    int n = 5;
   struct process a[n];

   for(int i=0; i<n; i++){
    a[i].arrival_time = 0;
    a[i].name = i+1;
    printf("Enter priority and burst time");
    scanf("%d %d", &a[i].priority, &a[i].burst_time);
   }

   cal(a, n);

   return 0;
}
