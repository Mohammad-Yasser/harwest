#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;
int acc[N];

int n, a, b, t;

inline bool can(int l, int o) {
	ll tot = 1LL * (l + o + min(l, o)) * a + acc[l] + acc[n - 1] - acc[n - 1 - o] + l + 1 + o;
	return tot <= t;
}

int bs(int l) {
	int low = 0, high = n - 1 - l, mid, ans = 0;
	while (low <= high) {
		mid = (low + high) >> 1;
		if (can(l, mid))
			low = mid + 1, ans = mid + l + 1;
		else
			high = mid - 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> a >> b >> t;
	string s;
	cin >> s;

	acc[0] = b * (s[0] == 'w');
	for (int i = 1; i < n; ++i)
		acc[i] = acc[i - 1] + b * (s[i] == 'w');


	int ans = 0;

	for (int i = 0; i < n; ++i)
		ans = max(ans, bs(i));
	cout << ans;

	return 0;
}
