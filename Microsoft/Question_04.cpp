
#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int r, int c) {
	
    return x >= 0 && x < r && y >= 0 && y < c;
}

vector<int> solve(vector<vector<int>>& matrix, int r, int c) {
	
	vector<int> ans(r*c), dx{0,1,0,-1}, dy{1,0,-1,0};
    int cx = 0, cy = 0, di = 0;
    
    for(int i=0; i<r*c; i++) {
        ans[i] = matrix[cx][cy];
        matrix[cx][cy] = -1;
        int nx = cx + dx[di];
        int ny = cy + dy[di];
        if(isValid(nx, ny, r, c) && matrix[nx][ny] != -1) {
            cx = nx;
            cy = ny;
        }
        else {
            di = (di + 1) % 4;
            cx = cx + dx[di];
            cy = cy + dy[di];
        }
            
    }
    
    return ans;

}

int main() {
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> a(n, vector<int> (m));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> a[i][j];
	
	vector<int> res = solve(a, n, m);
	
	for(int i=0; i<(int)res.size(); i++) {
		cout << res[i] << ' ';
	}
	
	return 0;
}
