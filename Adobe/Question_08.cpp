
#include <bits/stdc++.h>
using namespace std;

int solve(string str) {

    int ans = 0, P = 1;
    for(int i=(int)str.length()-1; i>0; i--) {
        if(str[i] >= '0' && str[i] <= '9') {
            ans += P*(str[i]-'0');
        }
        else {
            return -1;
        }
        P *= 10;
    }
    if(str[0] == '-')
        ans = -ans;
    else if(str[0] >= '0' && str[0] <= '9')
        ans += P*(str[0]-'0');
    else
        return -1;
    return ans;
    
}

int main() {
	
	string s;
	cin >> s;
	
	cout << solve(s);
	
	return 0;
}
