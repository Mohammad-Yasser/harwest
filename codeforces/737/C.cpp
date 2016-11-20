#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;

int a[N];
int s;
int n;

int cnt[N];
int cnt_ab[N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif
	cin >> n >> s;
	--s;

	bool s_w = false;
	int cnt_zeroes = 0;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i == s && a[i]) {
			s_w = true;
		}
		if (i != s && a[i] == 0) {
			++cnt_zeroes;
		}
		if (i != s && a[i] != 0) {
			++cnt[a[i]];
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (cnt[i] == 0) {
			++cnt_ab[i];
		}
		cnt_ab[i] += cnt_ab[i - 1];
		cnt[i] += cnt[i - 1];
	}

	int mn = n;

	for (int i = 0; i < n; ++i) {
		int ab = cnt_ab[i];
		if (cnt_zeroes + cnt[n] - cnt[i] >= ab) {
			mn = min(mn, cnt_zeroes + cnt[n] - cnt[i]);
		} else {
			mn = min(mn, ab);
		}
	}

	cout << mn + s_w;

	return 0;
}
