#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MX = 1e5 + 1;
ll pw3[MX];

unordered_map<ll, pair<int, ll> > memo;

pair<int, ll> solve(ll m) {
	auto it = memo.insert( { m, { } });
	if (!it.second) return it.first->second;
	pair<int, ll> res = { 0, 0 };
	if (!m) return res;
	int x = upper_bound(pw3, pw3 + MX, m) - pw3 - 1;
	res = solve(m - pw3[x]);
	++res.first;
	res.second += pw3[x];

	if (--x) {
		pair<int, ll> o2 = solve(pw3[x + 1] - pw3[x] - 1);
		++o2.first;
		o2.second += pw3[x];
		res = max(res, o2);
	}

	return memo[m] = res;
}

int main() {
	for (int i = 1; i < MX; ++i)
		pw3[i] = 1LL * i * i * i;
	ll m;
	cin >> m;
	auto ans = solve(m);
	cout << ans.first << ' ' << ans.second << '\n';
}
