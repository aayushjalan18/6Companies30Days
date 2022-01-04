
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> solve(vector<string>& string_list) {

    map<vector<int>,int> mp;
    vector<vector<string>> ans;
    int cn = 0;
    
    for(auto s : string_list) {
        
        vector<int> f(26,0);
        for(auto c : s)
            f[c-'a']++;
        
        if(mp.find(f) != mp.end())
            ans[mp[f]].push_back(s);
        else {
            mp[f] = (int)ans.size();
            ans.push_back({s});
        }
    }
    
    return ans;
}

int main() {
	
	int n;
	cin >> n;
	
	vector<string> vs(n);
	for(int i=0; i<n; i++)
		cin >> vs[i];
		
	vector<vector<string>> res = solve(vs);
	for(auto r : res) {
		for(auto s : r)
			cout << s << ' ';
		cout << '\n';
	}
	
	return 0;
}
