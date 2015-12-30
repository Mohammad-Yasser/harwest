#include <bits/stdc++.h>
using namespace std;

int h, w;

int memo[501][501][2];

string grid[501];

int dp(int i, int j, bool b) {
    if (i >= h or j >= w) return 0;
    int &ret = memo[i][j][b];
    if (ret != -1) return ret;

    ret = 0;
    if (b)
        ret += (grid[i + 1][j] == '.' && grid[i][j] == '.');
    else
        ret += (grid[i][j] == '.' && grid[i][j + 1] == '.');
    return ret += dp(i + 1, j, b) + dp(i, j + 1, b) - dp(i + 1, j + 1, b);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fill(grid, grid + 501, string(501, '#'));
    memset(memo, -1, sizeof memo);

    cin >> h >> w;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> grid[i][j];

    int q;
    cin >> q;
    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        --r1, --c1, --r2, --c2;

        int ans = 0;
        ans += dp(r1, c1, 1) - dp(r1, c2 + 1, 1) - dp(r2, c1, 1) + dp(r2, c2 + 1, 1);
        ans += dp(r1, c1, 0) - dp(r1, c2, 0) - dp(r2 + 1, c1, 0) + dp(r2 + 1, c2, 0);

        cout << ans << '\n';
    }
}
