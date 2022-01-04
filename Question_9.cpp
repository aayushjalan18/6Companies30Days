
#include <bits/stdc++.h>
using namespace std;

string solve(string S) {
	
	string ans;
        
    stack<int> st;
    for(int i=0; i<(int)S.length(); i++) {
        st.push(i+1);
        if(S[i] == 'I') {
            while(!st.empty()) {
                ans += to_string(st.top());
                st.pop();
            }
        }
    }
    st.push((int)S.length()+1);
    while(!st.empty()) {
        ans += to_string(st.top());
        st.pop();
    }
    
    return ans;
    
}

int main() {
	
	string str;
	cin >> str;
	
	cout << solve(str) << '\n';
	
	return 0;
}
