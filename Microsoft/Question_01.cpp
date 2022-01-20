
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int n)  { 
	
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
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
    
    for(int j=sum/2; j>=0; j--) {
        if(dp[n][j])
            return sum - 2*j;
    }
    
    return 0;
} 

int main() 
{
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto& e : a)
		cin >> e;
		
	cout << solve(a,n);
	
	return 0;
}
