
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a, int n, long long k) {

   if(k <= 1)
        return 0;
    
    int ans = 0, j = 0;
    long long prod = 1;
    
    for(int i=0; i<n; i++) {
        
        prod = prod * 1LL * a[i];
        while(prod >= k)
            prod /= (a[j++] * 1LL);
        ans += (i - j + 1);
    }
    
    return ans; 
}

int main() {
	
	int n;
	cin >> n;
	
	long long k;
	cin >> k;
	
	vector<int> a(n);
	for(auto& e : a)
		cin >> e;
	
	cout << solve(a,n,k) << '\n';
	
	return 0;
}
