
#include <bits/stdc++.h>
using namespace std;

string solve(string str1, string str2) {
	
    int gcd = __gcd((int)str1.length(), (int)str2.length());
        
    if((str1+str2) == (str2+str1))
       return str1.substr(0,gcd);
        
    return "";
}

int main() {
	
	string str1, str2;
	cin >> str1 >> str2;
	
	cout << solve(str1, str2) << '\n';
	
	return 0;
}
