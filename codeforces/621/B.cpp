#include <bits/stdc++.h>
using namespace std;

#define nC2(x) (x * (x-1) / 2)

long long diag[2003][2];

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		++diag[x + y][0];
		++diag[x - y + 1000][1];
	}
	long long ans = 0;
	for (int i = 0; i < 2003; ++i)
		ans += nC2(diag[i][0])+ nC2(diag[i][1]);
	cout << ans ;

	return 0;
}
