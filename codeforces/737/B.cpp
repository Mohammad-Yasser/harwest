#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif

	int n, a, b, k;
	cin >> n >> a >> b >> k;
	string grid;
	cin >> grid;
	grid = "1" + grid + "1";
	n = grid.size();
	int last_one = 0;
	int cnt_pos = 0;
	for (int i = 1; i < n; ++i) {
		if (grid[i] == '1') {
			cnt_pos += (i - last_one - 1) / b;
			last_one = i;
		}
	}

	int res = max(0, cnt_pos - a + 1);
	cout << res << '\n';

	last_one = 0;
	for (int i = 1; i < n && res > 0; ++i) {
		if (grid[i] == '0' && i - last_one == b) {
			cout << i << ' ';
			last_one = i;
			--res;
		}
		if (grid[i] == '1') {
			last_one = i;
		}
	}

	return 0;
}
