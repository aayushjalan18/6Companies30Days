
#include <bits/stdc++.h>
using namespace std;

void fun(int i, int j, vector<vector<int>>& dp, char& ch, string& ans) {
    if(i == j) {
        ans.push_back(ch);
        ch++;
    }
    else {
        ans.push_back('(');
        fun(i, dp[i][j], dp, ch, ans);
        fun(dp[i][j]+1, j, dp, ch, ans);
        ans.push_back(')');
    }
}

string solve(vector<int>& p) {
    
    int n = (int)p.size() - 1;
    
    vector<vector<int>> temp(n, vector<int> (n, INT_MAX));
    for(int i=0; i<n; i++)
        temp[i][i] = 0;
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int l=2; l<=n; l++) {
        for(int i=0; i<n-l+1; i++) {
            int j = i+l-1;
            for(int k=i; k<j; k++) {
                int v = temp[i][k] + temp[k+1][j] + (p[i]*p[k+1]*p[j+1]);
                if(v < temp[i][j]) {
                    temp[i][j] = v;
                    dp[i][j] = k;
                }
            }
        }
    }
    
    string ans;
    char ch = 'A';
    
    fun(0, n-1, dp, ch, ans);
    
    return ans;
}

int main() {
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
		
	cout << solve(a) << '\n';
	
	return 0;
}
