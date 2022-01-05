
#include <bits/stdc++.h>
using namespace std;

int* solve(int *arr, int n) {
	
	long long c1 = (n*1LL*(n+1))/2;
    long long c2 = (n*1LL*(n+1)*1LL*(2*n+1))/6;
    
    for(int i=0; i<n; i++) {
        c1 -= (arr[i]*1LL);
        c2 -= (arr[i]*1LL*arr[i]);
    }
    
    c2 = c2/c1;
    
    int *ans = new int(2);
    
    ans[0] = (c2-c1)/2;
    ans[1] = (c2+c1)/2;
    
    return ans;
}

int main() {
	
	int n;
	cin >> n;
	
	int *arr = new int(n);
	for(int i=0; i<n; i++)
		cin >> arr[i];
		
	int *res = solve(arr, n);
	
	for(int i=0; i<2; i++)
		cout << res[i] << ' ';
	
	return 0;
}
