#include<stdio.h>


int mutex = 1, full =0, empty = 3, x =0;

int wait(int s){
   return --s;
}

int signal(int s){
   return ++s;
}

void producer(){
  mutex =  wait(mutex);
  full = signal(full);
  empty = wait(empty);
  x++;
  printf("\n Producer produces the item %d", x);
  mutex = signal(mutex);
}

void consumer(){
  mutex =  wait(mutex);
  full = wait(full);
  empty = signal(empty);
  printf("\n consumer consumes the item %d", x);
  x--;
  mutex = signal(mutex);
}

int main(){
    int n;
   printf("1. producer\n2. consumer \n3.exit");

   while(1){
     printf("Enter your choice");
     scanf("%d", &n);

     switch(n){
    case 1:
        if(mutex == 1 && empty != 0){
            producer();
            break;
        }else{
            printf("Buffer is full");
        }

            case 2:
        if(mutex == 1 && full != 0){
            consumer();
            break;
        }else{
            printf("Buffer is full");
        }

            case 3:
                exit(0);
                break;
     }
   }
   return 0;

}

