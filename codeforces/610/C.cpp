#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
//  freopen("test.in", "rt", stdin);
#endif

    int k;
    cin >> k;

    vector<string> ans = { "*" };
    /*
     * 00 00
     * 10 10
     * 00 11
     * 10 01
     */

    while (k--) {
        for (auto &s : ans)
            s += s;
        int sz = ans.size();
        for (int i = 0; i < sz; ++i) {
            ans.push_back(ans[i]);
            for (int j = sz; j < 2 * sz; ++j)
                if (ans[i][j] == '*') ans[i][j] = '+' ;
                else ans[i][j] = '*' ;
        }
    }

    for (auto &s : ans)
        cout << s << '\n';

    return 0;

}
