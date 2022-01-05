
#include <bits/stdc++.h>
using namespace std;

string solve(string s) {
	
	int temp = 0;
    string ans = "";
    stack<pair<string,int>> st;
    
    for(int i=0; i<(int)s.length(); i++) {
        
        if(s[i] >= 'a' && s[i] <= 'z')
            ans.push_back(s[i]);
        else if(s[i] >= '0' && s[i] <= '9')
            temp = temp*10 + (s[i]-'0');
        else if(s[i] == '[') {
            st.push({ans,temp});
            ans = "";
            temp = 0;
        }
        else {
            int x = st.top().second;
            string s = st.top().first;
            st.pop();
            while(x--) {
                s += ans;
            }
            ans = s;
            temp = 0;
        }
    }
    
    return ans;
    
}

int main() {
	
	string s;
	cin >> s;
	
	cout << solve(s) << '\n';
	
	return 0;
}
