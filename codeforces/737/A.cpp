#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;

ll n, k, s, t;
ll gas[N];
pair<ll, ll> cars[N];

bool can(ll fuel) {
	ll total = 0;
	ll pos = 0;
	for (int i = 0; i < k; ++i) {
		if (gas[i] - pos > fuel) {
			return false;
		}
		total += 2 * (gas[i] - pos) - min(gas[i] - pos, fuel - (gas[i] - pos));
		pos = gas[i];
	}
	return (total <= t);
}

ll bs() {
	ll low = 0, high = 2e9 + 1, mid, ans = -1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (can(mid)) {
			ans = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif
	cin >> n >> k >> s >> t;
	for (int i = 0; i < n; ++i) {
		cin >> cars[i].first >> cars[i].second;
	}

	for (int i = 0; i < k; ++i) {
		cin >> gas[i];
	}

	sort(gas, gas + k);
	gas[k++] = s;

	ll fuel = bs();

	if (fuel == -1) {
		cout << -1;
		return 0;
	}

	ll res = -1;
	for (int i = 0; i < n; ++i) {
		if (cars[i].second >= fuel) {
			if (res == -1 || res > cars[i].first) {
				res = cars[i].first;
			}
		}
	}
	cout << res;

	return 0;
}
