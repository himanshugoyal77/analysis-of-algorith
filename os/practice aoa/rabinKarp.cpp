#include <bits/stdc++.h>
using namespace std;
#define d 10

void search(char text[], char pat[], int q){
    int n = strlen(text);
    int m = strlen(pat);
    int h=1, p=0, t=0;

    for(int i=0; i<m-1; i++){
        h = (d * h) % q;
    }

    for(int i=0; i<m; i++){
        p = (d * p + pat[i]) % q ;
        t = (d * t + text[i]) % q ;  
    }
    int i, j;
    for( i=0; i<n-m; i++){
        if(p == t){
            for(j=0; j<m; j++){
                if(text[i+j] != pat[j]) 
                 { 
                    break;
                  }
            }

            if (j== m) 
            cout << "Pattern found at index " << i << endl;
        }
        
        if(i<n-m){
          t = (d * (t - text[i] * h) + text[i+m]) % q;

          if(t<0){
            t = t+q;
          }
        }
    }
}

int main()
{
  char text[] = "ABCCDDAEFG";
  char pattern[] = "EFG";
  int q = 13;
  search(text,pattern, q);
	return 0;
}

