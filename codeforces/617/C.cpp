#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2003;
pair<int, int> f1, f2, flowers[N];
pair<ll, int> d[N];
bool covered[N];
inline ll dist(pair<int, int> a, pair<int, int> b) {
	ll x = a.first - b.first, y = a.second - b.second;
	return x * x + y * y;
}
int main() {
	int n;
	cin >> n;
	cin >> f1.first >> f1.second >> f2.first >> f2.second;
	for (int i = 0; i < n; ++i) {
		cin >> flowers[i].first >> flowers[i].second;
		d[i+1] = {dist(flowers[i],f1),i};
	}
	sort(d + 1, d + n + 1);
	ll mn = 1e17;

	for (int i = 0; i <= n; ++i) {
		memset(covered, 0, sizeof covered);
		for (int j = 1; j <= i; ++j)
			covered[d[j].second] = 1;
		ll furthest = 0;
		for (int j = 0; j < n; ++j)
			if (!covered[j]) furthest = max(furthest, dist(flowers[j], f2));
		mn = min(mn, d[i].first + furthest);
	}

	cout << mn;

	return 0;
}
