
#include <bits/stdc++.h>
using namespace std;

int solve(int target, vector<int>& nums) {
	
	  int n = (int)nums.size();
    int j = 0, s = 0, ans = n+1;
    
    for(int i=0; i<n; i++) {
        s += nums[i];
        while(s >= target) {
            ans = min(ans, i-j+1);
            s -= nums[j++];
        }
    }
    
    return ans == n+1 ? 0 : ans;
	
}

int main() {
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
		
	int target;
	cin >> target;
	
	cout << solve(target, a) << '\n';
	
	return 0;
}
