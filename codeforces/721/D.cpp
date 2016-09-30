#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;

int n, k, x;
ll ans[N];

bool neg = false;

void solve() {
	if (!neg) {
		int ind = 0;
		for (int i = 1; i < n; ++i) {
			if (abs(ans[i]) <= abs(ans[ind])) {
				ind = i;
			}
		}
		int tmp = min(1LL * k, (abs(ans[ind]) + x) / x);
		k -= tmp;
		if (ans[ind] < 0)
			ans[ind] += x * tmp;
		else
			ans[ind] -= x * tmp;
	}

	priority_queue<pair<ll, int>> q;
	for (int i = 0; i < n; ++i) {
		q.push( { -abs(ans[i]), i });
	}

	while (k--) {
		auto curr = q.top();
		q.pop();
		if (ans[curr.second] < 0)
			ans[curr.second] -= x;
		else
			ans[curr.second] += x;
		q.push( { -abs(ans[curr.second]), curr.second });
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k >> x;

	for (int i = 0; i < n; ++i) {
		cin >> ans[i], neg ^= (ans[i] < 0);
	}

	solve();

	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';

}
