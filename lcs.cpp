
#include <bits/stdc++.h>
using namespace std;

vector<char> res ;

int lcs(string X, string Y, int m, int n)
{
	if (m == 0 || n == 0)
		return 0;
	if (X[m - 1] == Y[n - 1]){
        res.push_back(X[m-1]);
		return 1 + lcs(X, Y, m - 1, n - 1);
	}
	else
		return max(lcs(X, Y, m, n - 1),
				lcs(X, Y, m - 1, n));
}

int main()
{
	string S1 = "AGGTAB";
	string S2 = "GXTXAYB";
	int m = S1.size();
	int n = S2.size();

	cout << "Length of LCS is " << lcs(S1, S2, m, n);
	for(int i=0; i<10; i++){
        cout<< res[i] << " " ;
	}

	return 0;
}

