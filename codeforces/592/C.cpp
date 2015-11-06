#include <bits/stdc++.h> 
using namespace std;

#define sz(v) (int)(v.size())

typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	ll t, w, b;

	cin >> t >> w >> b;

	if (w / __gcd(w, b) > t / b) {
		w = min(min(w, b) - 1, t);
		ll g = __gcd(w, t);
		cout << w / g << '/' << t / g;
		return 0;
	}

	ll lcm = w / __gcd(w, b) * b;

	ll cnt = (t / lcm + 1) * min(w, b) - max(0LL, min(w, b) - t % lcm - 1) - 1;

	ll g = __gcd(cnt, t);

	cout << cnt / g << '/' << t / g;

}
