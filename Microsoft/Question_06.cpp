
#include <bits/stdc++.h>
using namespace std;

void fun(vector<vector<char>>& V, vector<string>& ans, vector<int>& a, int n, int i=0, string s="") {
        
    if(i == n) {
        ans.push_back(s);
        return;
    }
    for(int j=0; j<(int)V[a[i]-2].size(); j++) {
        s.push_back(V[a[i]-2][j]);
        fun(V, ans, a, n, i+1, s);
        s.pop_back();
    }
}

vector<string> solve(vector<int>& a, int n) {
	
	vector<vector<char>> V{{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        
    vector<string> ans;
    
    fun(V, ans, a, n);
    
    return ans;
	
}

int main() {
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	vector<string> res = solve(a, n);
	
	for(int i=0; i<(int)res.size(); i++) {
		cout << res[i] << ' ';
	}
	
	return 0;
}
