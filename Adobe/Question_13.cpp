
#include <bits/stdc++.h>
using namespace std;

int LCS(vector<int> V) {
        
    vector<int> R;
    for(int i=0; i<(int)V.size(); i++) {
        auto it = lower_bound(R.begin(), R.end(), V[i]);
        if(it != R.end())
            *it = V[i];
        else
            R.push_back(V[i]);
    }
    
    return (int)R.size();
}
  
int solve(vector<int> A, vector<int> B, int N, int M) {
    
    unordered_set<int> b;
    for(int i=0; i<M; i++)
        b.insert(B[i]);
        
    vector<int> a;
    for(int i=0; i<N; i++) {
        if(b.find(A[i]) != b.end()) {
            a.push_back(A[i]);
        }
    }
    
    return (N + M - 2*LCS(a));
    
}

int main() {
	
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	for(auto& e : a)
		cin >> e;
		
	vector<int> b(m);
	for(auto& e : b)
		cin >> e;
		
	cout << solve(a, b, n, m);
	
	return 0;
}
