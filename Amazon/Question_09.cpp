
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& mat) {
	
	int v1[9][9] = {0}, v2[9][9] = {0}, v3[9][9] = {0};
        
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(mat[i][j] != 0) {
                int n = mat[i][j] - 1;
                int k = (i/3)*3 + (j/3);
                if(v1[i][n] || v2[j][n] || v3[k][n])
                    return 0;
                v1[i][n] = v2[j][n] = v3[k][n] = 1;
            }
        }
    }
    
    return 1;
}

int main() {
	
	vector<vector<int>> mat(9, vector<int> (9));
	
	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
			cin >> mat[i][j];
	
	cout << solve(mat) << '\n';
	
	return 0;
}
