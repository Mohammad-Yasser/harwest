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

	map<int, int> a, b;
	int n, q, w;
	cin >> n ;
	for (int i = 0; i < n; cin >> q >> w, a[q]++, ++b[w], ++i)
		;
	n = 0;
	for (map<int, int>::iterator it = a.begin(); it != a.end();
			n += it->second * b[it->first], ++it) ;
	cout << n ;

		return 0;
}
