
#include <bits/stdc++.h>
using namespace std;

int fun(vector<vector<int>>& dp, vector<int>& A, int i, int j) {
    
    if(i == j)
        return A[i];
    if(i+1 == j)
        return max(A[i],A[j]);
    if(dp[i][j] == -1) {
        dp[i][j] = max(A[i]+min(fun(dp,A,i+2,j),fun(dp,A,i+1,j-1)),A[j]+min(fun(dp,A,i+1,j-1),fun(dp,A,i,j-2)));
    }
    return dp[i][j];
}

int solve(vector<int>& A, int n) {
    
    vector<vector<int>> dp(n, vector<int> (n,-1));
    return fun(dp, A, 0, n-1);
}

int main() {
	
	int n;
	cin >> n;
	
	vector<int> coins(n);
	for(auto& c : coins)
		cin >> c;
	
	cout << solve(coins, n);
	
	return 0;
}
