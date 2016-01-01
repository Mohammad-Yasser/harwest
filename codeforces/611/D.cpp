#include <bits/stdc++.h>
using namespace std;

int z[5003][5003], n;

string s;

int memo[5003][5003];

const int MOD = 1000000007;

int dp(int curr, int last) {
    if (curr > n) return 0;
    if (curr == n) return 1;
    int &ret = memo[curr][last];
    if (ret != -1) return ret;
    ret = dp(curr + 1, last);

    if (s[curr] == '0') return ret;

    if (2 * curr - last <= n
      && s[min(curr - 1, z[last][curr] + last)]
        < s[min(2 * curr - last - 1, curr + z[last][curr])])
        ret = (ret + dp(2 * curr - last, curr)) % MOD;
    else if (2 * curr - last + 1 <= n)
      ret = (ret + dp(2 * curr - last + 1, curr)) % MOD;
    return ret;

}

int main() {
    srand(time(0));
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    memset(memo, -1, sizeof memo);

    cin >> n >> s;

    for (int i = n - 1; i >= 0; --i)
        for (int j = n - 1; j >= i; --j)
            z[i][j] = (s[i] == s[j]) * (1 + z[i + 1][j + 1]);

    cout << dp(1, 0);
    return 0;

}
