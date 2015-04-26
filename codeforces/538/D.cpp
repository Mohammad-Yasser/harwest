#include <bits/stdc++.h>
using namespace std;

bool npos[111][111], att[51][51];

int n;
inline bool val(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < n;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    string s[n];
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (s[i][j] == '.') {
                for (int a = 0; a < n; ++a)
                    for (int b = 0; b < n; ++b)
                        if (s[a][b] == 'o')
                          npos[i - a + 50][j - b + 50] = 1;
            }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (s[i][j] == 'x') {
                bool bv = 0;
                for (int a = 0; a < n; ++a)
                    for (int b = 0; b < n; ++b) {
                        if (s[a][b] == 'o' && !npos[i - a + 50][j - b + 50]) bv = 1;
                    }
                if (!bv) {
                    cout << "NO";
                    return 0;
                }
            }
    cout << "YES" << endl;
    n = 2 * n - 1;
    string ans[n];
    fill(ans, ans + n, string(n, '.'));
    ans[n / 2][n / 2] = 'o';
    npos[50][50] = 1;
    for (int dx = -50; dx < 51; ++dx)
        for (int dy = -50; dy < 51; ++dy)
            if (val(n / 2 + dx, n / 2 + dy) && !npos[dx + 50][dy + 50]) ans[n / 2 + dx][n / 2 + dy] =
              'x';
    for (int i = 0; i < n; ++i)
        cout << ans[i] << endl;

}
