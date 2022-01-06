
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr) {
	
	int n = (int)arr.size();
        
    if(n < 3)
        return 0;
    
    vector<int> left(n,0);
    for(int i=1; i<n; i++) {
        if(arr[i-1] < arr[i])
            left[i] = 1+left[i-1];
    }
    
    vector<int> right(n,0);
    for(int i=n-2; i>=0; i--) {
        if(arr[i] > arr[i+1])
            right[i] = 1+right[i+1];
    }
    
    int ans = 0;
    for(int i=1; i<n-1; i++) {
        if(left[i] && right[i])
            ans = max(ans,1+left[i]+right[i]);
    }
    
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
