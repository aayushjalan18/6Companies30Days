
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int n) {
	
	if(n == 1)
        return arr[0];
    
    for(int i=2; i<n; i++) {
        if(i > 2)
            arr[i] += max(arr[i-2],arr[i-3]);
        else
            arr[i] += arr[0];
    }
    
    return max(arr[n-1],arr[n-2]);
}

int main() {
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto& e : a)
		cin >> e;
		
	cout << solve(a, n);
}
