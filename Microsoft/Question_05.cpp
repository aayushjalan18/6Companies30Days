
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& price, int n) {
	
	vector<int> V{-1}, ans(n);
       
    for(int i=0; i<n; i++) {
       
        while(V.back() != -1 && price[V.back()] <= price[i])
            V.pop_back();
        ans[i] = i - V.back();
        V.push_back(i);
    }
   
   return ans;
	
}

int main() {
	
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	for(int i=0; i<n; i++)
			cin >> a[i];
	
	vector<int> res = solve(a, n);
	
	for(int i=0; i<(int)res.size(); i++) {
		cout << res[i] << ' ';
	}
	
	return 0;
}
