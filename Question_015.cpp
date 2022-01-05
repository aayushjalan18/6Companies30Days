
#include <bits/stdc++.h>
using namespace std;

int solve(int k, vector<int>& nums) {
	
	vector<int> a(k,0);
    for(int i=0; i<(int)nums.size(); i++)
        a[nums[i]%k]++;
    
    if(a[0] & 1)
        return false;
    
    int L = 1, R = k-1;
    while(L <= R) {
        if(L == R) {
            if(a[L] & 1)
                return false;
        }
        else {
            if(a[L] != a[R])
                return false;
        }
        L += 1;
        R -= 1;
    }
    
    return true;
	
}

int main() {
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
		
	int k;
	cin >> k;
	
	cout << solve(k, a) << '\n';
	
	return 0;
}
