
#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> arr) {
	
	int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    
    if(sum & 1) {
        return 0;
    }

    vector<vector<bool>> dp(n+1, vector<bool> (sum+1));
    for(int i=0; i<=n; i++)
        dp[i][0] = true;
    for(int j=1; j<=sum; j++)
        dp[0][j] = false;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= arr[i-1])
                dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
        }
    }
    
    return (int)dp[n][sum/2];
}

int main() {
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for(auto &e : arr)
		cin >> e;
	
	cout << (solve(n,arr) ? "YES" : "NO");
	
	return 0;
}
