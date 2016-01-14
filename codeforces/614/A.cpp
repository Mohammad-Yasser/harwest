#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif

	ll l, r, k;
	cin >> l >> r >> k;
	bool b = 0;
	ll tmp = 1;
	while (1) {
		if (tmp >= l && tmp <= r) cout << tmp << ' ', b = 1;
		if (tmp > r / k) break;
		tmp *= k;
	}
	if (!b) cout << -1;

}
