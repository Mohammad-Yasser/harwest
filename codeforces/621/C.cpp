#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int l[N], r[N];

#define prob(x)  (1.0*(r[x] / p - l[x] / p) / (r[x] - l[x]))

int n, p;

double memo[N][2][2];
double dp(int ind, bool last, bool first = 0) {
	if (ind == 1) first = last;
	auto &ret = memo[ind][last][first];
	if (ret == ret) return ret;
	ret = 0;
	double pr = prob(ind);

	if (ind == n - 1) {
		if (!first) ret = pr * 2000;
		if (!last) ret += pr * 2000;
//		cout << ind << ' ' << last << ' ' << first << ' ' << ret << '\n';

		return ret;
	}

	if (last)
		ret = (1 - pr) * dp(ind + 1, 0, first) + pr * (2000 + dp(ind + 1, 1, first));
	else
		ret = (1 - pr) * dp(ind + 1, 0, first) + pr * (4000 + dp(ind + 1, 1, first));

//	cout << ind << ' ' << last << ' ' << first << ' ' << ret << '\n';

	return ret;
}

int main() {
	memset(memo, -1, sizeof memo);
	cin >> n >> p;

	for (int i = 0; i < n; ++i)
		cin >> l[i] >> r[i], --l[i];

	double ans = dp(0, 0);

	cout << fixed << setprecision(7) << ans;

	return 0;
}
