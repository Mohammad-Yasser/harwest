#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



bool valid(ll s, ll x) {
	while ((s & 1) == (x & 1) && (x & 1) == 1)
		s >>= 1, x >>= 1;

	if ((s & 1) != (x & 1)) return 0;

	short carry = 0;
	for (int i = 0; i < 64; ++i) {
		short a = (s >> i) & 1, b = (x >> i) & 1;
		if (!a && !b && carry) return 0;
		if ((a != b) && (!i or (((s >> (i - 1)) & 1) == 1 && ((x >> (i - 1)) & 1) == 1))) return 0;
		if (b && !a) carry = 1;
		if (!b && a) carry = 0;

	}
	return !carry;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int N = 2000;
	ll s, x;
	cin >> s >> x;

	if (valid(s, x))
		cout << (1LL << __builtin_popcountll(x)) - 2 * (s == x);
	else
		cout << 0;
}
