
#include <bits/stdc++.h>
using namespace std;

long long solve(vector<vector<long long>>& dp, int sum, int x, int b, int MOD) {
        
    if(sum == pow(b,x))
        return dp[sum][b] = 1;
    if(sum < pow(b,x))
        return dp[sum][b] = 0;
    if(dp[sum][b] != -1)
        return dp[sum][b];
    int res = pow(b,x);
    return dp[sum][b] = (solve(dp, sum-res, x, b+1, MOD) + solve(dp, sum, x, b+1, MOD)) % MOD;
}

int main() {
	
	int n, x;
	cin >> n >> x;
	
	vector<vector<long long>> dp(n+1, vector<long long> (n+1,-1));
	
	cout << solve(dp, n, x, 1, 1000000007);
	
	return 0; 
}
