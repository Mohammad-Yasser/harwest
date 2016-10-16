#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;

int n;
int powers[N];
int cnt[N];

int main() {
	ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> powers[i];
		++cnt[powers[i]];
	}

	for (int i = 1; i < N; ++i) {
		cnt[i] += cnt[i - 1];
	}

	sort(powers, powers + n);

	ll mx = 0;

	for (int i = 0; i < n; ++i) {
	    if (i && powers[i] == powers[i-1]) continue;
		int curr = powers[i];
		ll res = 0;
		for (int j = curr; j < N; j += curr) {
			res += 1LL * (cnt[min(j + curr - 1,N-1)] - cnt[j - 1]) * j;
//			cout << curr << ' ' << j << ' ' << cnt[j + curr - 1] << ' ' << cnt[j - 1] << ' ' << res
//			  << endl;
		}
//		cout << curr << ' ' << res << endl;
		mx = max(res, mx);
	}

	cout << mx;
}