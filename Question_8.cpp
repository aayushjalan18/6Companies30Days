
#include <bits/stdc++.h>
using namespace std;

int solve(string str) {
	
	if(str[0] == '0') {
        return 0;
    }
    
    int n = (int)str.length();
    int M = 1e9 + 7;
    
    vector<long long> a(n+1);
    a[0] = a[1] = 1;
    
    for(int i=2; i<=n; i++) {
        
        int k = (str[i-2]-'0')*10 + (str[i-1]-'0');
        if(str[i-1] == '0') {
            if(k == 10 || k == 20)
                a[i] = a[i-2];
            else
                return 0;
        }
        else {
            a[i] = a[i-1];
            int k = (str[i-2]-'0')*10 + (str[i-1]-'0');
            if(k > 9 && k < 27)
                a[i] = (a[i] + a[i-2]) % M;
        }
    }
    
    return (int)a[n]%M;
    
}

int main() {
	
	string str;
	cin >> str;
	
	cout << solve(str) << '\n';
	
	return 0;
}
