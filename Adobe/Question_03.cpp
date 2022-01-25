
#include <bits/stdc++.h>
using namespace std;

int power(int b, int p, int M) {
    
    int r = 1;
    while(p) {
        if(p & 1)
            r = (r * 1LL * b) % M;
        b = (b * 1LL * b) % M;
        p >>= 1;
    }
    return r%M;
}
  
int solve(int N, int K) {
    
    vector<vector<long long>> dp(N+1, vector<long long> (K+1,0));
    
    long long sum = 1;
    long long MOD = 1e9 + 7;
    
    for(int i=1; i<=N; i++) {
        dp[i][0] = (sum * 21) % MOD;
        sum = dp[i][0];
        for(int j=1; j<=K; j++) {
            if(j > i)
                dp[i][j] = 0;
            else if(j < i)
                dp[i][j] = (dp[i-1][j-1] * 5LL) % MOD;
            else
                dp[i][j] = power(5, i, MOD);
            sum = (sum + dp[i][j]) % MOD;
        }
    }
    
    return (int)sum;
}

int main() {
	
	int n, k;
	cin >> n >> k;
	
	cout << solve(n,k);
	
	return 0;
}
