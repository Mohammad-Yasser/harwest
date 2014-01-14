#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;

const int OO = (int) 2e9;
const double eps = 1e-9;

int main() {

	
	int n[4];

	for (int i = 0; i < 4; cin >> n[i], ++i)
		;
	sort(n,n+4) ;
	if (n[3] < n[2]+n[1] or n[2] < n[0]+n[1]) cout << "TRIANGLE" ;
	else if (n[2]==n[1]+n[0] or n[3] == n[2]+n[1]) cout << "SEGMENT" ;
	else cout << "IMPOSSIBLE" ;
	return 0;
}
