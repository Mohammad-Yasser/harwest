#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int a[m];
	for (int i = 0; i < m; cin >> a[i++])
		;
	sort(a, a + m);
	int mn = a[--n] - a[0];
	for (int i = 1; i + n < m; mn = min(mn, a[n + i] - a[i++]))
		;
	cout << mn;
}
