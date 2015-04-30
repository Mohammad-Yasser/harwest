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
    ll now = base, result = 1;
    for (int i = power.size() - 1; i >= 0; --i) {
        result = (result * fastPowerMod(now, power[i] - '0', mod)) % mod;
        now = fastPowerMod(now, 10, mod);
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
