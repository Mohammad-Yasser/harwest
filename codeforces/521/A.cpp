#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD = 1e9 + 7;

ll power(ll a, ll p) {
	if (!p) return 1;
	ll res = power(a, p >> 1);
	res = res * res % MOD ;
	if (p & 1LL) res = res * a % MOD;
	return res;
}

int cnt[128];

int main() {
	int n, mx = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		mx = max(mx, ++cnt[s[i]]);
	int cntMx = 0;
	for (int i = 0; i < 128; ++i)
		cntMx += cnt[i] == mx;
	cout << power(cntMx , n) ;
}
