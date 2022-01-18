
#include <bits/stdc++.h>
using namespace std;

int solve(int K, int N, vector<int>& A) {
	
	vector<vector<int>> dp(K+1, vector<int> (N+1));
        
    for(int i=0; i<=K; i++)
        dp[i][0] = 0;
    for(int j=0; j<=N; j++)
        dp[0][j] = 0;
    
    for(int i=1; i<=K; i++) {
        int prev = INT_MIN;
        for(int j=1; j<N; j++) {
            prev = max(prev, dp[i-1][j-1]-A[j-1]);
            dp[i][j] = max(dp[i][j-1], A[j]+prev);
        }
    }
    
    return dp[K][N-1];
    
}

int main() {
	
	int n, k;
	cin >> n >> k;
	
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
		
	cout << solve(k, n, a) << '\n';
	
	return 0;
}
