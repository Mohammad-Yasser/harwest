#include <bits/stdc++.h>
using namespace std;

int memo[501][501][2], n, m, b, mod, a[501];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> b >> mod;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int k = 0; k <= b; ++k)
		memo[m][k][0] = memo[m][k][1] = 1;
	for (int i = n - 1; i >= 0; --i)
		for (int j = m - 1; j >= 0; --j)
			for (int k = b; k >= 0; --k) {
				if (k + a[i] <= b) {
					if (j + 1 == m)
						++memo[j][k][i % 2] %= mod;
					else
						(memo[j][k][i % 2] += memo[j + 1][k + a[i]][i % 2]) %= mod;
				}
				if (i != n - 1 && k + a[i + 1] <= b)
				  (memo[j][k][i % 2] += memo[j + 1][k + a[i + 1]][!(i % 2)]) %= mod;
			}

	cout << memo[0][0][0] << endl;

}
