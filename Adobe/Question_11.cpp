
#include <bits/stdc++.h>
using namespace std;

string solve(string s) {
	
    string ans, temp;
    for(auto c : s) {
        if(isupper(c)) {
            if(!temp.empty())
                ans = ans + temp + " ";
            temp.clear();
            temp.push_back(char((int)c + 32));
        }
        else
            temp.push_back(c);
    }
    ans = ans + temp;
    return ans;
}


int main() {
	
	string s;
	cin >> s;
	
	cout << solve(s);
	
	return 0;
}
