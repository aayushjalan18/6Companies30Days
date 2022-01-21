
#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& a) {
	
	int n = (int)a.size();
    for(int i=0; i<n/2; i++) {
        for(int j=i; j<n-1-i; j++) {
            swap(a[i][j], a[j][n-1-i]);
            swap(a[j][n-1-i], a[n-1-i][n-1-j]);
            swap(a[n-1-i][n-1-j], a[n-1-j][i]);
        }
    }
	
}

int main() {
	
	int n;
	cin >> n;
	
	vector<vector<int>> a(n, vector<int> (n));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> a[i][j];
			
	solve(a);
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
