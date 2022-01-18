
#include <bits/stdc++.h>
using namespace std;

void solve(char nuts[], char bolts[], int n) {
	
	char v[9] = {'!','#','$','%','&','*','@','^','~'};
	    
    map<char,int> nut, bolt;
    
    for(int i=0; i<n; i++) {
        nut[nuts[i]]++;
        bolt[bolts[i]]++;
    }
    
    int j = 0;
    for(int i=0; i<9; i++) {
        if(nut[v[i]] > 0 && bolt[v[i]] > 0) {
           nuts[j] = bolts[j] = v[i];
           j++;
        }
    }

}

int main() {
	
	int n;
	cin >> n;
	
	char nuts[n];
	for(int i=0; i<n; i++)
		cin >> nuts[i];
		
	char bolts[n];
	for(int i=0; i<n; i++)
		cin >> bolts[i];
	
	solve(nuts, bolts, n);
	
	for(int i=0; i<n; i++)
		cout << nuts[i] << ' ';
	cout << '\n';
	for(int i=0; i<n; i++)
		cout << bolts[i] << ' ';
	cout << '\n';
	
	return 0;
}
