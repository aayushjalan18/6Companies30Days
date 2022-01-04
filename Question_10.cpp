
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7; // 10M

vector<int> solve(int k) {
	
	vector<int> a(N);
	for(int i=0; i<N; i++)
		a[i] = rand()%(1000000000);

	priority_queue<int,vector<int>,greater<int>> pq; 
	for(int i=0; i<k; i++)
		pq.push(a[i]);
		
	for(int i=k; i<N; i++) {
		if(a[i] > pq.top()) {
			pq.pop();
			pq.push(a[i]);
		}
	}
	
	vector<int> ans;
	while(!pq.empty()) {
		ans.push_back(pq.top());
		pq.pop();
	}
	
	return ans;
    
}

int main() {
	
	int k = 10;
	
	vector<int> res = solve(k);
	for(auto r : res)
		cout << r << ' ';
	
	return 0;
}
