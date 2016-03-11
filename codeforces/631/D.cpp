#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;

pair<ll, char> con[2 * N], t[N], p[N];
int z[2 * N];
int n, m;
void genZ() {
	int n = ::n + m - 1;
	int l, r, k;
	l = r = 0;
	for (int i = 1; i < n; ++i) {
		if (i > r) {
			l = r = i;

			while (r < n && con[r - l] == con[r])
				r++;
			z[i] = r - l;
			r--;
		}
		else {

			k = i - l;

			if (z[k] < r - i + 1)
				z[i] = z[k];

			else {

				l = i;
				while (r < n && con[r - l] == con[r])
					r++;
				z[i] = r - l;
				r--;
			}
		}
	}
}

inline bool can(pair<ll, char> &p1, pair<ll, char> &p2) {
	return p1.second == p2.second && p1.first >= p2.first;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	// if (m < 2)
	char tmp;

	for (int i = 0; i < n; ++i) {
		cin >> t[i].first >> tmp >> t[i].second;
		while (i && t[i - 1].second == t[i].second)
			t[i - 1].first += t[i].first, --i, --n;
	}

	for (int i = 0; i < m; ++i) {
		cin >> p[i].first >> tmp >> p[i].second;
		while (i && p[i - 1].second == p[i].second)
			p[i - 1].first += p[i].first, --i, --m;
		if (i)
		  con[i - 1] = p[i];
	}

	if (m == 1) {
		ll ans = 0;
		for (int i = 0; i < n; ++i)
			if (t[i].second == p[0].second)
			  ans += max(0LL, t[i].first - p[0].first + 1);
		cout << ans;
		return 0;
	}

	con[m - 2] = {-1,-1};
	for (int i = m - 1; i < n + m - 1; ++i)
		con[i] = t[i - m + 1];

	genZ();
	int ans = 0;

	for (int i = m; i < n + 1; ++i)
		ans += z[i] == m - 2 && can(con[i - 1], p[0]) && can(con[i + z[i]], p[m - 1]);

	cout << ans;

}
