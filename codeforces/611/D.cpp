#include <bits/stdc++.h>
using namespace std;

const int base = 10 + rand() % 123;

long long hsh[5003][5003], n;

string s;

int memo[5003][5003];

bool ls(int a, int b, int c, int d) {
    if (hsh[a][b] == hsh[c][d]) return 0;
    int low = 0, high = b - a, mid, ans;
    while (low <= high) {
        mid = (low + high) / 2;
        if (hsh[a][a + mid] == hsh[c][c + mid])
            low = mid + 1;
        else {
            ans = mid;
            high = mid - 1;
        }
    }
    return s[a + ans] < s[c + ans];
}

const int MOD = 1000000007;

int dp(int curr, int last) {
    if (curr > n) return 0;
    if (curr == n) return 1;
    int &ret = memo[curr][last];
    if (ret != -1) return ret;
    ret = dp(curr + 1, last);

    if (s[curr] == '0') return ret;

    if (2 * curr - last <= n && ls(last, curr - 1, curr, 2 * curr - last - 1))
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

    for (int i = 0; i < n; ++i) {
        hsh[i][i] = s[i] - '0' + 1;
        for (int j = i + 1; j < n; ++j)
            hsh[i][j] = (hsh[i][j - 1] * base + s[j] - '0' + 1) % MOD;
    }

    cout << dp(1, 0);
    ;

    return 0;

}
