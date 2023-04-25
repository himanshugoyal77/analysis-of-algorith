#include<stdio.h>

int main(){

   int block_cap,file_cap;
   printf("Enter number of blocks : ");
   scanf("%d", &block_cap);
   printf("Enter number of files : ");
   scanf("%d", &file_cap);

   int blocks[block_cap], files[file_cap];

   for(int i=0; i<block_cap; i++){
     printf("Enter block %d : ", i+1);
     scanf("%d", &blocks[i]);
   }

    for(int i=0; i<file_cap; i++){
     printf("Enter file %d : ", i+1);
     scanf("%d", &files[i]);
   }

   printf("file_no\t\tfile_size\t\tblock_no\t\tblocl_size\t\tfragments\n");
   int temp[block_cap];
   for(int i=0; i<block_cap; i++){
    temp[i] = -1;
   }
   for(int f=0; f<file_cap; f++){
    printf("%d\t\t", f+1);
    printf("%d\t\t", files[f]);
    for(int b=0; b<block_cap; b++){
        if(temp[b]==-1){
           if(files[f]<blocks[b]){
            printf("%d\t\t", b+1);
            printf("%d\t\t", blocks[b]);
            temp[b] = 1;

            int fra = blocks[b] - files[f];
            printf("%d\t\t", fra);
            break;
          }
        }
    }
    printf("\n");
   }

   return 0;
}
