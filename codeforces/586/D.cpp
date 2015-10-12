#include <bits/stdc++.h> 
using namespace std;

int memo[101][3];

struct Train {
	int row, start, end;
} trains[33];

int n, k;

bool check(int x, int y, bool ch) {
	if (!x) return 1;
	for (int i = 0; i < 33; ++i) {

		if (trains[i].row == y && x >= trains[i].start - 2 * (x - ch)
		  && x <= trains[i].end - 2 * (x - ch))
		  return 0;

		if (!ch) {
			ch = 1;

			if (trains[i].row == y && x >= trains[i].start - 2 * (x - ch)
			  && x <= trains[i].end - 2 * (x - ch))
			  return 0;

			ch = 0;
		}
	}
	return 1;
}

int DP(int x, int y) {
	if (x == n) return 1;
	int &ret = memo[x][y];
	if (ret != -1) return ret;

	ret = 0;

	for (int i = 0; i < 3; ++i)
		if (abs(i - y) < 2 && check(x + 1, y, 1) && check(x + 1, i, 0)) {
			ret = ret or DP(x + 1, i);
		}


	return ret;
}

int main() {

	int t;
	cin >> t;
	while (t--) {
		memset(memo, -1, sizeof memo);

		cin >> n >> k;
		Train tmp = { -1, 1e3, -1 };
		fill(trains, trains + 33, tmp);
		int st;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < n; ++j) {
				char c;
				cin >> c;
				if (c == 's')
					st = i;
				else if (isalpha(c)) {
					trains[c - 'A'].row = i;
					trains[c - 'A'].start = min(trains[c - 'A'].start, j);
					trains[c - 'A'].end = max(trains[c - 'A'].end, j);
				}
			}
		cout << (DP(0, st) ? "YES\n" : "NO\n");
	}
}
