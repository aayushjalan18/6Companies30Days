
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& arr, int n, long long s) {
	
	int i = 0, j = 0;
    long long sum = 0;
    while(i < n) {
        sum += arr[i++]*1LL;
        while(sum > s) {
            sum -= arr[j++]*1LL;
        }
        if(sum == s) {
            return {j+1,i};
        }
    }
    return {-1};
    
}

int main() {
	
	int n, s;
	cin >> n >> s;
	
	vector<int> a(n);
	for(auto& e : a)
		cin >> e;
		
	vector<int> res = solve(a, n, s*1LL);
	
	for(auto r : res)
		cout << r << ' ';
	
	return 0; 
}
