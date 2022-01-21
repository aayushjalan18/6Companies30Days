
#include <bits/stdc++.h>
using namespace std;

vector<int> dx{0,1,1,1,0,-1,-1,-1};
vector<int> dy{1,1,0,-1,-1,-1,0,1};

bool isValid(int x, int y, int n, int m) {
        
    return x >= 0 && x < n && y >= 0 && y < m;
}
    
int dfs(vector<vector<int>>& G, int x, int y, int n, int m) {
	
    if(!isValid(x,y,n,m) || !G[x][y])
        return 0;
    G[x][y] = 0;
    int c = 0;
    for(int k=0; k<8; k++)
        c += dfs(G, x+dx[k], y+dy[k], n, m);
    return 1 + c;
}

int solve(vector<vector<int>>& grid) {
	
	int n = (int)grid.size(), m = (int)grid[0].size();
    int ans = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j])
                ans = max(ans, dfs(grid, i, j, n, m));
        }
    }
    
    return ans;
	
}

int main() {
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> grid(n, vector<int> (m));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> grid[i][j];
	
	cout << solve(grid);
	
	return 0;
}
