#include <bits/stdc++.h>
using namespace std;
string s;
int m, memo[1003][11][11];
bool DP_rec(int idx, int diff, int lst) {
    if (idx == m)
        return 1;
    int &b = memo[idx][diff][lst];
    if (b + 1)
        return b;
    b = 0;
    for (int i = diff + 1; i <= s.size(); ++i)
        if (s[i - 1] == '1' && lst != i)
            b |= DP_rec(idx + 1, i - diff, i);
    return b;
}
void iter() {
    for (int i = 0; i < 11; i++)
        for (int j = i; j < 11; ++j)
            memo[m][i][j] = 1;
    for (int idx = m - 1; idx >= 0; --idx)
        for (int diff = 10; diff >= 0; --diff)
            for (int lst = 10; lst >= 0; lst--) {
                for (int i = diff + 1; i <= s.size(); ++i)
                    if (s[i - 1] == '1' && lst != i)
                        memo[idx][diff][lst] |= memo[idx + 1][i - diff][i];
            }
}
void print(int idx, int diff, int lst) {
    if (idx == m)
        return;
    for (int i = diff + 1; i <= s.size(); ++i)
        if (s[i - 1] == '1' && lst != i
                && (memo[idx + 1][i - diff][i] == 1 or idx + 1 == m)) {
            cout << i << ' ';
            print(idx + 1, i - diff, i);
            return;
        }
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    cin >> s >> m;
    memset(memo,-1,sizeof memo) ;
    DP_rec(0, 0, 0);
    if (memo[0][0][0])
        cout << "YES\n", print(0, 0, 0);
    else
        cout << "NO\n";
}
