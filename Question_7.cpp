
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, int k) {
	
	m %= n;
	
    if(m == 0) {
    	return k == 1 ? n : k-1;
    }
    
    if(m <= n-k+1)
    	return m+k-1;
    
    m -= (n-k+1);
    
    return m == 0 ? n : m;
    
}

int main() {
	
	int n, m, k;
	cin >> n >> m >> k;
	
	cout << solve(n, m, k) << '\n';
	
	return 0;
}
