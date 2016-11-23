#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
//	freopen("o.txt", "wt", stdout);
#endif

	int n, m;
	cin >> n >> m;
	int ans = 1e5;
	while (m--) {
		int a, b;
		cin >> a >> b;
		ans = min(ans, b - a + 1);
	}

	cout << ans << '\n';
	for (int i = 0; i < n; ++i) {
		cout << i % ans << ' ';
	}

	return 0;
}
