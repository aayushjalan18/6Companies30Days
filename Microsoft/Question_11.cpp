
#include <bits/stdc++.h>
using namespace std;

vector<string> solve(int N) {
	
	vector<string> ans(N);
	queue<string> q;
	q.push("1");
	
	for(int i=0; i<N; i++) {
	    
	    ans[i] = q.front();
	    q.push(q.front()+"0");
	    q.push(q.front()+"1");
	    q.pop();
	}
	
	return ans;
}

int main() {
	
	int n;
	cin >> n;
	
	vector<string> res = solve(n);
	
	for(int i=0; i<n; i++)
		cout << res[i] << ' ';
}

