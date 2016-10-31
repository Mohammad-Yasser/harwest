#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 502;

char memo[N][N][N];

int n, k;
int arr[N];

bool dp(int ind, int x, int k) {
	if (k == 0 && x == 0) return true;
	if (x > k) return false;
	if (k < 0 || x < 0) return false;
	if (ind == n) return false;

	char &ret = memo[ind][x][k];
	if (ret != -1) return ret;

	ret = false;
	ret |= dp(ind + 1, x - arr[ind], k - arr[ind]);
	ret |= dp(ind + 1, x, k - arr[ind]);
	ret |= dp(ind + 1, x, k);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif

	memset(memo, -1, sizeof memo);
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	vector<int> res;

	for (int i = n - 1; i >= 0; --i)
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < N; ++k) {
				dp(i, j, k);
			}

	for (int i = 0; i < N; ++i) {
		if (dp(0, i, k)) {
			res.push_back(i);
		}
	}

	cout << res.size() << '\n';
	for (int x : res)
		cout << x << ' ';

}
