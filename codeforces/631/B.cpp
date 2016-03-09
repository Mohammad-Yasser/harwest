#include <bits/stdc++.h>

using namespace std;

const int N = 5003;

int r[N][2], c[N][2];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= k; ++i) {
		int tmp, ind, clr;
		cin >> tmp >> ind >> clr;
		if (tmp == 1)
			r[ind][0] = clr, r[ind][1] = i;
		else
			c[ind][0] = clr, c[ind][1] = i;
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (r[i][1] > c[j][1])
				cout << r[i][0] << " \n"[j == m];
			else
				cout << c[j][0] << " \n"[j == m];

}
