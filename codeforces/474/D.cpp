#include <bits/stdc++.h>
using namespace std;
long long fct[11];
const int MOD = 1e9 + 7;
int main() {

    int t, k, ans[(int) 1e5 + 3], a, b;
    cin >> t >> k;
    for (int i = 0; i < k; ++i)
        ans[i] = 1;
    for (int i = k; i < 1e5 + 3; ++i)
        ans[i] = (ans[i - 1] + ans[i - k]) % MOD;
    ans[0] = 0;
    for (int i = 1; i < 1e5 + 3; ++i)
        ans[i] = (ans[i - 1] + ans[i]) % MOD;
    while (t--) {
        cin >> a >> b;
        cout << (ans[b] - ans[a - 1] + MOD) % MOD << '\n';
    }

}
