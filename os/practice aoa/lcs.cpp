#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int n, int m, vector<vector<int>> &dp){
    if(n < 0 || m < 0) return 0;

    if(dp[n+1][m+1] != 0) return dp[n+1][m+1];

    if(s1[n] == s2[m]){
        return dp[n+1][m+1] = 1 + lcs(s1, s2, n-1, m-1, dp);
    }else{
        return dp[n+1][m+1] = max(
            lcs(s1, s2, n-1, m, dp),
            lcs(s1, s2, n, m-1, dp)
        );
    }
}

int main(){
    string s1 = "himanshu";
    string s2 = "uuhauuu";
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    cout<< lcs(s1, s2, n-1, m-1, dp);
    cout<<endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    int i=n, j=m; 
    string ans = "";
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            ans += s1[i-1];
            i--;
            j--;
        }else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
}