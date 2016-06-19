#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int lg[N];
int sparseTable[N][20];
int arr[N];
int n;

inline void build() {
	lg[0] = -1 ;
	for (int i = 0; i < n;) {
		sparseTable[i][0] = i;
		++i;
		lg[i] = lg[i - 1] + (i == (i & -i));
	}

	for (int j = 1; (1 << j) <= n; ++j)
		for (int i = 0; i + (1 << j) <= n; ++i) {
			int a = sparseTable[i][j - 1], b = sparseTable[i + (1 << (j - 1))][j - 1];
			sparseTable[i][j] = (arr[a] > arr[b] ? a : b);
		}

}

inline int getMax(int i, int j) {
	int l = lg[j - i + 1];
	int a = sparseTable[i][l], b = sparseTable[j - (1 << l) + 1][l];
	return (arr[a] > arr[b] ? a : b);
}

long long dp[N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i + 1 < n; ++i)
		cin >> arr[i], --arr[i];

	build();

	long long res = 0;
	for (int i = n - 2; i >= 0; --i) {
		if (arr[i] == n - 1)
			dp[i] = n - i - 1;
		else {
			int ind = getMax(i + 1, arr[i]);
			dp[i] = n - 1 - arr[i] + dp[ind] + ind - i;
		}

		res += dp[i];
	}

	cout << res;
}
