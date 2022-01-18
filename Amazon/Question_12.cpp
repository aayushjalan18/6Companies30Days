
#include <bits/stdc++.h>
using namespace std;

string solve(long long int n) {
            
    string ans;
    
    while(n) {
        
        int r = n%26;
        if(r == 0) {
            ans.push_back('Z');
            n = n/26 - 1;
        }
        else {
            ans.push_back(char(r-1+'A'));
            n = n/26;
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main() {
	
	long long n;
	cin >> n;
	
	cout << solve(n) << '\n';
	
	return 0;
}
