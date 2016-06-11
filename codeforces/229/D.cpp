#include <bits/stdc++.h> 
using namespace std;

const int N = 5e3 + 1;

int memo[N][N];
int acc[N];
int ht[N];
int nxt[N][N];
int n;

int dp(int ind, int lst) {
	if (ind == n - 1) return 0;
	int &ret = memo[ind][lst];
	if (ret != -1) return ret;
	if (acc[ind + 1] - acc[lst] <= ht[ind + 1]) return ret = dp(ind + 1, ind + 1);
	ret = 1 + dp(ind + 1, lst);
	if (nxt[lst][ind] < n) ret = min(ret, nxt[lst][ind] - ind - 1 + dp(nxt[lst][ind], ind + 1));
	return ret;
}

int main() {
	memset(memo, -1, sizeof memo);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> ht[i];
		acc[i + 1] = acc[i] + ht[i];
	}

	for (int i = 0; i < n; ++i) {
		int curr = i;
		for (int j = i; j < n; ++j) {
			while (curr <= n && 2 * acc[j + 1] - acc[i] > acc[curr])
				++curr;
			nxt[i][j] = curr - 1;
		}
	}

	cout << dp(0, 0) << endl;
}

