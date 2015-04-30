#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fastPowerMod(ll base, ll power, ll mod) {
	if (!power) return 1;
	ll result = fastPowerMod(base, power / 2, mod);
	result = (result * result) % mod;
	if (power % 2) result = (result * base) % mod;
	return result;
}

ll fastPowerMod(ll base, string power, ll mod) {
	ll tens = 1, result = 1;
	reverse(power.begin(), power.end());
	for (int i = 0; i < power.size(); ++i) {
		result = (result * fastPowerMod(fastPowerMod(base, tens, mod), power[i] - '0', mod)) % mod;
		tens *= 10;
	}
	return result;

}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s;
	cin >> s;

	int result = 1;
	for (int i = 2; i < 5; ++i)
		result = (result + fastPowerMod(i, s, 5)) % 5;

	cout << result;

}
