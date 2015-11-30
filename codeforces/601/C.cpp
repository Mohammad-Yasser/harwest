#include<bits/stdc++.h>
using namespace std;

double ex[2][100005];
double acc[100005];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	ex[1][0] = m - 1;
	acc[0] = 0;
	acc[1] = m - 1;
	for (int j = 2; j <= n * m + 1; ++j)
		acc[j] = ex[1][j - 1] + acc[j - 1];

	int score = 0;
	bool b;
	for (int i = 0; i < n; ++i) {
		b = i & 1;
		int x;
		cin >> x;
		score += x;

//		for (int j = 0; j <= 5; ++j)
//			cout << i << ' ' << j << ' ' << acc[j] << endl;
//
//		cout << endl;

		for (int j = n * m; j >= 0; --j) {
			ex[b][j] = (acc[j] - acc[max(0,j - m)]) / (m - 1);
			if (j >= x) ex[b][j] -= ex[!b][j - x] / (m - 1);
		}

		acc[1] = ex[b][0];

		for (int j = 2; j <= n * m + 1; ++j)
			acc[j] = ex[b][j - 1] + acc[j - 1];

//		for (int j = 0; j <= 5; ++j)
//			cout << i << ' ' << j << ' ' << ex[b][j] << endl;
//		cout << endl;
		memset(ex[!b], 0, sizeof ex[!b]);

	}

	double sm = accumulate(ex[b] + n, ex[b] + score, 1.0);

	cout << fixed << setprecision(10) << sm;

	return 0;
}
