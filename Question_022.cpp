
#include <bits/stdc++.h>
using namespace std;

string solve(string A){
		    
    queue<char> q;
    vector<int> v(26, 0);
    
    string ans;
    
    for(auto c : A) {
        v[c-'a']++;
        q.push(c);
        while(!q.empty() && v[q.front()-'a'] > 1)
            q.pop();
        if(q.empty())
            ans.push_back('#');
        else
            ans.push_back(q.front());
    }
    
    return ans;
}

int main() {
	
	string s;
	cin >> s;
		
	cout << solve(s) << '\n';
	
	return 0;
}
