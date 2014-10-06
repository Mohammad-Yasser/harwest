#include <bits/stdc++.h>
using namespace std;

int main() {
    // I didn't find this idea by myself only
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    string ans[] = { "NO", "YES" };
    cout
            << ans[s1[0] == '>' && s2[0] == '^' && s1[n - 1] == '<'
                    && s2[m - 1] == 'v'
                    or s1[0] != '>' && s2[0] != '^' && s1[n - 1] != '<'
                            && s2[m - 1] != 'v'];

}
