#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> arrival {
  { 0, 0, 0 }, { 0, 0, 1 }, { 0, 1, 1 }, { 1, 1, 1 }
};

vector<vector<ll>> leave {
  { 0, 0, 0 }, { 1, 0, 0 }, { 1, 1, 0 }, { 1, 1, 1 }
};

int main() {
	ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	ll arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];

	if (max( { arr[0], arr[1], arr[2] }) == 1) {
		cout << 0;
		return 0;
	}
	ll mn = LLONG_MAX;

	for (auto& a : arrival)
		for (auto& b : leave) {
			ll tmp[3];
			ll mx = 0;
			ll ans = 0;

			for (int i = 0; i < 3; ++i) {
				tmp[i] = arr[i] - a[i] - b[i];
				mx = max(mx, tmp[i]);
			}
			for (int i = 0; i < 3; ++i) {
				ans += mx - tmp[i];
			}
			mn = min(mn, ans);
		}

	cout << mn;
}