#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    char c;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m;
                cin >> c, s[i] += c == '.' ? (i % 2 == j % 2 ? 'B' : 'W') : '-', ++j)
            ;
    for (int i = 0; i < n; cout << s[i++] << '\n')
        ;
}
