
#include <bits/stdc++.h>
using namespace std;

void fun(vector<string>& ans, int L, int R, string S="") {
    
    if(L == 0 && R == 0) {
        ans.push_back(S);
        return;
    }
    if(L > 0) {
        fun(ans, L-1, R, S+"(");
    }
    if(R > L) {
        fun(ans, L, R-1, S+")");
    }
}
    
vector<string> solve(int n) {
    
    vector<string> ans;
    fun(ans, n, n);
    return ans;
}

int main() {
	
	int n;
	cin >> n;
	
	vector<string> res = solve(n);
	
	for(auto r : res)
		cout << r << '\n';
	
	return 0;
}
