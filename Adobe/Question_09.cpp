
#include <bits/stdc++.h>
using namespace std;

string solve(string N) { 
    
    int n = (int)N.length();
    
    string S = N.substr(0,n/2);
    if(!next_permutation(S.begin(), S.end())) {
        return "-1";
    }
    
    string T = S;
    reverse(T.begin(), T.end());
    
    if(n & 1)
        S.push_back(N[n/2]);
    
    return S + T;
    
}

int main() {
	
	string s;
	cin >> s;
	
	cout << solve(s);
	
	return 0;
}
