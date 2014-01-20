#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m, k;
	unsigned long long int y;
	cin >> n >> m >> k;
	vector<vector<int> > x;
	x.resize(n);
	for (int i = 0; i < n;++i)
		for (int ii = 0; ++ii <= m; cin >> y, x[i].push_back(y))
			;
	y = 0;

	for (int i = 0; i < m; ++i)
		for (int ii = 1+i; ii < m; y++, ++ii)
			;
	cout << y<<endl ;

	for (int i = 0; i < m; ++i)
			for (int ii = 1+i; ii < m;++ii)
				!k ? (cout << i+1 << " " << ii+1 << endl) : (cout<<ii+1 << " " << i+1 << endl);
}
