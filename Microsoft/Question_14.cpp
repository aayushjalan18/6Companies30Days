
#include <bits/stdc++.h>
using namespace std;

int solve(int D) {
	
	int N = ceil((-1.0 + sqrt(1 + 8.0 * D)) / 2);
    int S = (N * (N+1))/2;
    
    int diff = S - D;
    
    if(diff & 1 ^ 1)
        return N;
    
    if(N & 1 ^ 1)
        return N+1;
    
    return N+2;
}

int main() {
	
	int target;
	cin >> target;
	
	cout << solve(target);
}
