
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& a, int n) {
	
	vector<int> suffix(n+1);
    suffix[n] = 0;
    for(int i=n-1; i>=0; i--) {
        suffix[i] = max(suffix[i+1],a[i]);
    }
    
    vector<int> ans;
    for(int i=0; i<n; i++) {
        if(a[i] >= suffix[i+1]) {
            ans.push_back(a[i]);
        }
    }
    
    return ans;
}

int main() {
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto& e : a)
		cin >> e;
		
	vector<int> res = solve(a, n);
	
	for(auto r : res) {
		cout << r << ' ';
	}
	
	return 0;
}
