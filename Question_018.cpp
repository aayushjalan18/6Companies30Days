
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, int k, vector<int>& arr) {
	
	arr.insert(arr.begin(), 0);
        
    multiset<int> ms;
    for(int i=0; i<k; i++)
        ms.insert(arr[i]);
        
    vector<int> ans;
    for(int i=k; i<=n; i++) {
        ms.insert(arr[i]);
        ms.erase(ms.find(arr[i-k]));
        auto it = ms.end();
        ans.push_back(*(--it));
    }
    
    return ans;
    
}

int main() {
	
	int n, k;
	cin >> n >> k;
	
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
		
	vector<int> res = solve(n, k, a);
	for(auto r : res)
		cout << r << ' ';
	
	return 0;
}
