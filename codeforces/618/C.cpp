#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

bool insideTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) {
	ll a = area(x1, y1, x2, y2, x3, y3);
	ll a1 = area(x, y, x2, y2, x3, y3);
	ll a2 = area(x1, y1, x, y, x3, y3);
	ll a3 = area(x1, y1, x2, y2, x, y);
	return a == a1 + a2 + a3;
}

pair<int, int> points[100005];

ll dist(pair<int, int> x, pair<int, int> y) {
	ll f = x.first - y.first, s = x.second - y.second;
	return f * f + s * s;
}

pair<ll, ll> slope(pair<int, int> x, pair<int, int> y) {
	ll a = y.second - x.second, b = y.first - x.first, g = __gcd(a, b);
	a /= g, b /= g;
	return {b,a};
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> points[i].first >> points[i].second;

	int ind1 = 1;

	for (int i = 1; i < n; ++i)
		if (dist(points[0], points[i]) < dist(points[0], points[ind1]))
		  ind1 = i;

	int ind = n - 1;

	for (int i = n - 1; i > 0; --i)
		if (i != ind1 && slope(points[0], points[ind1]) != slope(points[0], points[i])) {
			ind = i;
			break;
		}

	for (int i = n - 2; i > 0; --i)
		if (i != ind1
		  && insideTriangle(points[0].first, points[0].second, points[ind1].first,
		    points[ind1].second,
		    points[ind].first, points[ind].second, points[i].first, points[i].second)) ind = i;

	cout << 1 << ' ' << ind1 + 1 << ' ' << ind + 1;

	return 0;
}