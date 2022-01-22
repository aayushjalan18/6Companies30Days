
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int>& arr, int k) {
	
	sort(arr.begin(), arr.end());
        
    set<vector<int>> st;
    for(int i=0; i<(int)arr.size(); i++) {
        for(int j=i+1; j<(int)arr.size(); j++) {
            int L = j+1;
            int R = (int)arr.size() - 1;
            while(L < R) {
                if((arr[i]+arr[j]+arr[L]+arr[R]) == k) {
                    st.insert({arr[i],arr[j],arr[L],arr[R]});
                    L += 1;
                    R -= 1;
                }
                else if((arr[i]+arr[j]+arr[L]+arr[R]) < k)
                    L += 1;
                else
                    R -= 1;
            }
        }
    }
    
    vector<vector<int>> ans;
    for(auto s : st)
        ans.push_back(s);
        
    return ans;
}

int main() {
	
	int n, k;
	cin >> n >> k;
	
	vector<int> arr(n);
	for(auto &a : arr)
		cin >> a;
	
	vector<vector<int>> res = solve(arr, k);
	
	for(auto re : res) {
		for(auto r : re)
			cout << r << ' ';
		cout << '\n';
	}
}
