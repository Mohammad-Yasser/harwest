#include <bits/stdc++.h>
using namespace std;

vector<bool> vec[18][30];

int n, m, n2p;

bool fn(int lvl, int ind, int b, bool val) {
    vec[lvl][b][ind] = val;
    if (lvl == n) return val;

    bool v2 = vec[lvl][b][ind - (ind % 2) + !(ind % 2)];
    val = (lvl % 2 ? val ^ v2 : val | v2);

    return fn(lvl + 1, ind / 2, b, val);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    n2p = round(pow(2, n));
    int arr[n2p];
    for (int i = 0; i < n2p; ++i)
        cin >> arr[i];

    for (int i = 0; i < 30; ++i) {
        vec[0][i].resize(n2p);
        for (int j = 0; j < n2p; ++j)
            vec[0][i][j] = (1 << i) & arr[j];
    }

    for (int b = 0; b < 30; ++b)
        for (int i = 1; i <= n; ++i) {
            vec[i][b].resize(vec[i - 1][b].size() / 2);
            for (int j = 0; j < vec[i][b].size(); ++j)
                vec[i][b][j] = (
                  i % 2 ?
                          vec[i - 1][b][2 * j] | vec[i - 1][b][2 * j + 1] :
                          vec[i - 1][b][2 * j] ^ vec[i - 1][b][2 * j + 1]);
        }

    while (m--) {

        int p, ab;
        cin >> p >> ab;
        --p;
        int ans = 0;
        for (int i = 0; i < 30; ++i) {
            ans |= (fn(0, p, i, !!(ab & (1 << i)))) << i;
        }
        cout << ans << '\n';
    }
}
