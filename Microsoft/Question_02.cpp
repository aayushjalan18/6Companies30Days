
#include <bits/stdc++.h>
using namespace std;

bool solve(int N, vector<pair<int, int> >& prerequisites) {
    
    vector<vector<int>> lst(N);
    vector<int> inDeg(N, 0);
    for(auto p : prerequisites) {
        lst[p.second].push_back(p.first);
        inDeg[p.first]++;
    }
    
    queue<int> q;
    
    for(int i=0; i<N; i++) {
        if(inDeg[i] == 0) {
            q.push(i);
        }
    }
    
    int c = 0;
    while(!q.empty()) {
        c++;
        for(auto v : lst[q.front()]) {
            inDeg[v]--;
            if(inDeg[v] == 0) {
                q.push(v);
            }
        }
        q.pop();
    }
    
    return c == N;
    
}

int main() {
	
	int n, p;
	cin >> n >> p;
	
	vector<pair<int,int>> a(p);
	for(auto& e : a)
		cin >> e.first >> e.second;
		
	cout << solve(n,a);
	
	return 0;
}
