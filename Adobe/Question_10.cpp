
#include <bits/stdc++.h>
using namespace std;

vector<string> solve(vector<string>& arr, int n) {
    
    unordered_map<string,int> ump;
    int mx = 0;
    for(int i=0; i<n; i++) {
        ump[arr[i]]++;
        mx = max(mx, ump[arr[i]]);
    }
    
    string ans;
    for(auto u : ump) {
        if(u.second == mx) {
            if(ans.empty() || u.first < ans) {
                ans = u.first;
            }
        }
    }
    
    return {ans, to_string(mx)};
}

int main() {
	
	int n;
	cin >> n;
	
	vector<string> vs(n);
	for(int i=0; i<n; i++)
		cin >> vs[i];
		
	vector<string> res = solve(vs, n);
	
	for(auto r : res)
		cout << r << ' ';
	
	return 0;
}
