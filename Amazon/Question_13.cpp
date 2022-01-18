
#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, int m) {
        
    return x >= 0 && x < n && y >= 0 && y < m;
}
    
int solve(vector<vector<int>>& grid) {
    
    vector<int> dx{1,0,-1,0};
    vector<int> dy{0,1,0,-1};
    int n = (int)grid.size();
    int m = (int)grid[0].size();
    
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 2)
                q.push({i,j});
        }
    }
    
    int ans = 0;
    
    while(!q.empty()) {
        
        queue<pair<int,int>> c;
        while(!q.empty()) {
            
            pair<int,int> p = q.front();
            q.pop();
            
            for(int j=0; j<4; j++) {
                if(isValid(p.first+dx[j],p.second+dy[j],n,m) && grid[p.first+dx[j]][p.second+dy[j]] == 1) {
                    c.push({p.first+dx[j],p.second+dy[j]});
                    grid[p.first+dx[j]][p.second+dy[j]] = 2;
                }
            }
        }
        
        q = c;
        ans++;
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 1)
                return -1;
        }
    }
    
    return max(ans-1,0);
    
}

int main() {
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> grid(n, vector<int> (m));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> grid[i][j];
	
	cout << solve(grid) << '\n';
	
	return 0;
}
