#include <bits/stdc++.h>
using namespace std;

double memo[101][101][101][3];

double DP(int r, int s, int p, int i) {
	double &res = memo[r][s][p][i];
	if (res == res) return res;
	if (!r && (!s or !p) or !s && !p) {
		if (!i) return res = !!r;
		if (i == 1) return res = !!s;
		if (i == 2) return res = !!p;
	}

	int all = r * s + s * p + r * p;
	double prs = 1.0 * r * s / all, prp = 1.0 * r * p / all, psp = 1.0 * s * p / all;
	res = (s ? prs * DP(r, s - 1, p, i) : 0) + (r ? prp * DP(r - 1, s, p, i) : 0)
	  + (p ? psp * DP(r, s, p - 1, i) : 0);

	return res;
}

int main() {
	memset(memo, -1, sizeof memo);
	int r, s, p;
	cin >> r >> s >> p;
	cout << fixed << setprecision(10) << DP(r, s, p, 0) << ' ' << DP(r, s, p, 1) << ' '
	  << DP(r, s, p, 2);
}
