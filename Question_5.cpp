
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull solve(int n) {
	
    ull ugly[n];
    ugly[0] = 1;
    
    int two = 0, three = 0, five = 0;
    
    for(int i=1; i<n; i++) {
        
        vector<ull> a{ugly[two]*2, ugly[three]*3, ugly[five]*5};
        ull mn = *min_element(a.begin(), a.end());
        
        ugly[i] = mn;
        
        if(mn == a[0])
            two++;
        if(mn == a[1])
            three++;
        if(mn == a[2])
            five++;
    }
    
    return ugly[n-1];
}  

int main() {
	
	int n;
	cin >> n;
	
	cout << solve(n) << '\n';
	
	return 0;
}
