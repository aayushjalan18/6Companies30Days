
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> A, int n) {
        
    if(n < 3)
        return n;
    
    vector<vector<int>> dp(n, vector<int> (n,2));
    int ans = 2;
    
    for(int j=n-2; j>0; j--) {
        int i = j-1, k = j+1;
        while(i >= 0 && k < n) {
            if(A[i]+A[k] < 2*A[j])
                k++;
            else if(A[i]+A[k] > 2*A[j])
                i--;
            else {
                dp[i][j] = dp[j][k]+1;
                ans = max(ans, dp[i][j]);
                i--;
                k++;
            }
        }
    }
    
    return ans;
}

int main() {
	
	int n;
	cin >> n;
	
	vector<int> A(n);
	for(auto &e : A)
		cin >> e;
		
	cout << solve(A,n);
	
	// your code goes here
	return 0;
}
