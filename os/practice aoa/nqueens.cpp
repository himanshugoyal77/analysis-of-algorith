#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define n 8

void printSol(int board[n][n])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
           if(board[i][j])
            cout << "Q ";
           else cout<<". ";
        printf("\n");
    }
}

bool isSafe(int board[][n], int row, int col){
    int i, j;

    for(i=0; i<col; i++){
        if(board[row][i]) return false;
    }

    for(i=row, j=col; i>=0 && j>=0; i--, j--){
          if(board[i][j]) return false;
    }

    for(i=row, j=col; i<n && j>=0; i++, j--){
          if(board[i][j]) return false;
    }

    return true;
}

bool solveUntil(int board[][n], int col){
    if(col >= n){
        return true;
    }

    for(int i=0; i<n; i++){
        if(isSafe(board, i, col)){
            board[i][col] = 1;
            
            if(solveUntil(board, col+1)){ return true;}

            board[i][col] = 0;
        }
    }

    return false;
}

bool nQueens(){
    int board[][n] = {{0, 0, 0, 0, 0,0, 0, 0}, 
                      {0, 0, 0, 0, 0, 0, 0, 0}, 
                      {0, 0, 0, 0, 0, 0, 0, 0}, 
                      {0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0}};

    if(solveUntil(board, 0) == false){
        cout<<"No possible Solutions"<<endl;
        return false;
    }
    
    printSol(board);
    return true;
}

int main(){
    nQueens();
    return 0;
}