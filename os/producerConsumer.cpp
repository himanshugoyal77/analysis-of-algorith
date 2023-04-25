#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int mutex=1, full=0, empty=3, x=0;

int wait(int s){
   return --s;
}

int signal(int s){
   return ++s;
}

void producer(){
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
     x++;
     cout<<"\n Producer produces Item no "<< x <<endl;
    mutex= signal(mutex);
}

void consumer(){
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
     cout<<"\n Producer produces Item no %d " << x<<endl;
     x--;
    mutex= signal(mutex);
}

int main(){
  int n;

  while(1){
        cout<<"Enter your choice"<<endl;
        cin>>n;
        switch(n){
       case 1:
        if(mutex == 1 && empty !=0){
            producer();
        }else{
           cout<<"Buffer is full"<<endl;
        }
        break;
        case 2:
        if(mutex == 1 && full !=0){
            consumer();
        }else{
           cout<<"Buffer is empty"<<endl;
        }
        break;
        case 3:
            exit(0);
            break;
        }

  }

  return 0;
}
