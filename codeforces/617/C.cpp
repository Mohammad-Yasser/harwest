#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2003;
pair<int, int> f1, f2, flowers[N];
pair<ll, int> d[N];
inline ll dist(pair<int, int> a, pair<int, int> b) {
	ll x = a.first - b.first, y = a.second - b.second;
	return x * x + y * y;
}
ll furthest[N];
int main() {
	int n;
	cin >> n;
	cin >> f1.first >> f1.second >> f2.first >> f2.second;
	for (int i = 0; i < n; ++i) {
		cin >> flowers[i].first >> flowers[i].second;
		d[i+1] = {dist(flowers[i],f1),i};
	}
	sort(d + 1, d + n + 1);
	for (int i = n; i; --i)
		furthest[i] = max(furthest[i + 1], dist(flowers[d[i].second], f2));

	ll mn = 1e17;

	for (int i = 0; i <= n; ++i)
		mn = min(mn, d[i].first + furthest[i + 1]);

	cout << mn;

	return 0;
}
