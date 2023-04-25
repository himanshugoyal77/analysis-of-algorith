#include<stdio.h>

int main(){
   int n = 5;
   int m = 3;

   int alloc[5][3] = {{0, 1, 0},{2, 0, 0},{3, 0, 2},{2, 1, 1},{0, 0, 2}};
   int max[5][3] ={ { 7, 5, 3 },

				{ 9, 0, 2 },
				{ 2, 2, 2 },
				{ 4, 3, 3 } };
    int availabe[3] = {3, 3, 2};

    int need[n][m], ind = 0, ans[n];
    int f[n];
    for(int i=0; i<n; i++){
        f[i] = 0;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            if(f[i] == 0){
                int flag = 0;
                for(int j=0; j<m; j++){
                    if(need[i][j] > availabe[j]){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    ans[ind++] = i;
                    for(int y=0; y<m; y++){
                        availabe[y]+=alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        printf("%d\n", f[i]);
    }

    int flag = 1;
    for(int i=0; i<n; i++){
        if(f[i]==0){
             flag = 0;
             printf("the following system is not safe\n");
             break;
        }
    }


    if(flag == 1){
          printf("the following system is safe sequence\n");
          for(int j=0; j<n-1; j++){
            printf("p%d ->", ans[j]);
          }
          printf("p%d", ans[n-1]);
    }

return 0;

}
