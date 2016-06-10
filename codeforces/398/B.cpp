#include <bits/stdc++.h> 
using namespace std;

const int N = 2e3 + 1;

double memo[N][N];

int n;

double dp(int rows, int cols) {
	if (!rows && !cols) return 0;
	auto &ret = memo[rows][cols];
	if (ret == ret) return ret;

	int free = (n * n - (n - rows) * (n - cols));

	double p = (double) free / (n * n);
	ret = 1 / p;

	if (cols) ret += (double) (cols * (n - rows)) / free * (dp(rows, cols - 1));
	if (rows) ret += (double) (rows * (n - cols)) / free * (dp(rows - 1, cols));
	if (cols && rows) ret += (double) (rows * cols) / free * (dp(rows - 1, cols - 1));


	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	int m;
	cin >> m;
	unordered_set<int> rows, cols;
	while (m--) {
		int x, y;
		cin >> x >> y;
		rows.insert(x);
		cols.insert(y);
	}
	memset(memo, -1, sizeof memo);
	cout << fixed << setprecision(9) << dp(n - rows.size(), n - cols.size()) << endl;

}

