#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007, MX = 200005;

typedef long long ll;

ll pwr(ll x, ll y) {
    ll ret = 1;
    while (y) {
        if (y & 1LL) ret = ret * x % MOD;
        x = x * x % MOD;
        y /= 2;
    }
    return ret % MOD;
}

int cnt[MX];
int lft[MX], rt[MX];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//  freopen("test.in", "rt", stdin);
#endif

    int m;
    cin >> m;

    ll ans = 1;
    for (int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        ++cnt[tmp];
    }

    ll prod = 1;
    for (int i = 2; i < MX; ++i) {
        lft[i] = prod;
        prod = prod * (cnt[i] + 1) % (MOD - 1);
    }
    prod = 1;
    for (int i = MX - 1; i >= 2; --i) {
        rt[i] = prod;
        prod = prod * (cnt[i] + 1) % (MOD - 1);
    }

    for (int i = 2; i < MX; ++i) {
        ll tmp = 1;
        ll p = 1LL * lft[i] * rt[i] % (MOD - 1);
        for (int j = 0; j < cnt[i]; ++j) {
            tmp = tmp * i % MOD;
            ans = ans * pwr(tmp, p) % MOD;
        }
    }

    cout << ans;

    return 0;

}
