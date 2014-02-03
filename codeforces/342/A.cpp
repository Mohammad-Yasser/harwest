#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);

	int a[8], q, n;
	fill(a,a+8,0) ;
	cin >> n;
	while (cin >> q && ++a[q])
		;
	if (a[5] or a[7] or a[1] * 3 != n or a[2] != a[6] + a[4] - a[3] or a[6]<a[3] && a[3]) {
		cout << -1;
		return 0;
	}
	while (a[4]-- && a[2]-- && cout << 1 << ' ' << 2 << ' ' << 4 <<endl) ;
	while (a[2]-- && cout << 1 << ' ' << 2 << ' ' << 6 <<endl) ;
	while (a[3]-- && cout << 1 << ' ' << 3 << ' ' << 6 <<endl) ;

//1 2 4
//1 2 6
//1 3 6

	return 0;
}
