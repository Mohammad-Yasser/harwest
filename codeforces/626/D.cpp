#include <bits/stdc++.h>
using namespace std;

int n;
int a[2003];

const int MX = 5003;
long double p1[MX];
long double p2[2 * MX];
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	long double pD = 1.0 / (n * (n - 1) / 2);
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			++p1[a[j] - a[i]];
	for (auto &x : p1)
		x *= pD;

	for (int i = 0; i < MX; ++i)
		for (int j = 0; j < MX; ++j)
			p2[i + j] += p1[i] * p1[j];

	long double ans = 0;

	for (int i = MX - 2; i >= 0; --i)
		p1[i] += p1[i + 1];
	for (int i = 0; i + 1 < MX; ++i)
		ans += p2[i] * p1[i + 1];

	cout << fixed << setprecision(11) << ans;

	return 0;
}
