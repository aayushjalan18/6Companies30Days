
#include <bits/stdc++.h>
using namespace std;

string solve(string src) {
	
    string ans;
  
    int i = 0, n = (int)src.length();
    while(i < n) {
        
        int cn = 1;
        while(i < n-1 && src[i] == src[i+1]) {
            i++;
            cn++;
        }
        ans.push_back(src[i++]);
        ans += to_string(cn);
    }
  
    return ans;
}  

int main() {
	
	string s;
	cin >> s;
	
	cout << solve(s) << '\n';
	
	return 0;
}
