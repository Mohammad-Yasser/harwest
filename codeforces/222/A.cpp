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

	int n, k,i=0;
	cin >> n >> k;
	int y[n];
	for (int var = 0; var < n; cin >> y[var], ++var)
			;

	for (i=k; i < n && y[i]==y[k-1] ; ++i) ;
	if (i<n) {cout <<-1;return 0;}
	for (i = k-2; i >=0 && y[i]==y[k-1]; --i) ;

	cout << i+1 ;
	return 0;
}
