#include<stdio.h>

int main(){
  int incomingStrem[] = {4, 1, 2, 4, 5};
  int pageFaults = 0, s;
  int frames = 3;
  printf(" Incoming \t frame1 \t frame2 \t frame 3");
  int temp[3];

  for(int i=0; i<frames; i++){
    temp[i] = -1;
  }

  for(int i=0; i<5; i++){
    s = 0;
    for(int j=0; j<frames; j++){
       if(incomingStrem[i] == temp[j]){
        s++;
        pageFaults--;
       }
    }
    pageFaults++;
    if(pageFaults <= frames && s==0){
        temp[i] = incomingStrem[i];
    }
    else if(s == 0){
        temp[(pageFaults -1) % frames] = incomingStrem[i];
    }
    printf("\n");
    printf("%d\t\t\t\t", incomingStrem[i]);
    for(int j=0; j<frames; j++){
        if(temp[j] != -1){
           printf("%d\t\t\t\t", temp[j]);
        }else{
               printf("-\t\t\t\t");
        }
    }
  }

  printf("total page faults %d", pageFaults);



  return 0;
}
