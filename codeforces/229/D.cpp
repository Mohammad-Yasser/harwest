#include <bits/stdc++.h> 
using namespace std;

const int N = 5e3 + 1;

int dp[N][N];
int acc[N];
int ht[N];
int nxt[N][N];
int n;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> acc[i + 1];
		acc[i + 1] += acc[i];
	}

	for (int i = 0; i < n; ++i) {
		int curr = i;
		for (int j = i; j >= 0; --j) {
			while (curr <= n && 2 * acc[i + 1] - acc[j] > acc[curr])
				++curr;
			nxt[i][j] = curr - 1;
		}
	}

	for (int i = n - 2; i >= 0; --i)
		for (int j = i; j >= 0; --j) {
			int &res = dp[i][j];
			res = 1 + dp[i + 1][j];
			if (nxt[i][j] < n) res = min(res, nxt[i][j] - i - 1 + dp[nxt[i][j]][i + 1]);
		}

	cout << dp[0][0] << endl;
}

