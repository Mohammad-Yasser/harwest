#include <bits/stdc++.h>

using namespace std;

const int OO = 1000;

int memo[501][501];
int arr[501];

int dp(int x, int y) {
	int &ret = memo[x][y];
	if (ret != -1) return ret;
	if (x == y) return ret = 1;
	if (x + 1 == y) return ret = 1 + (arr[x] != arr[y]);
	ret = OO;
	ret = 2 * (arr[x] != arr[y]) + dp(x + 1, y - 1);

	for (int i = x; i < y; ++i)
		ret = min(ret, dp(x, i) + dp(i + 1, y));

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(memo, -1, sizeof memo);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cout << dp(0, n - 1);

}
