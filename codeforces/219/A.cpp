#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, gc, sz = 0, ss = 0;
    char c;
    cin >> n;
    set<char> ch;
    int nc[26];
    fill(nc, nc + 26, 0);
    while (cin >> c) {
        ch.insert(c);
        nc[c - 'a']++;
        gc = nc[c - 'a'];
        ++sz;
    }
    if (n == 1) {
        for (int i = 0; i < 26; ++i)
            cout << string(nc[i], char(i + 'a'));
        return 0;
    }
    bool b = 0;
    for (int i = 0; i < 26; ++i) {
        if (nc[i] != 0 && __gcd(gc, nc[i]) > 1)
            gc = __gcd(gc, nc[i]);
        else if (nc[i] != 0)
            b = 1;
        ss += nc[i];
    }
    if (b or gc % n) {
        cout << -1;
        return 0;
    }
    ss /= gc;
    for (int j = 0; j < sz / ss; ++j)
        for (int i = 0; i < 26; ++i)
            cout << string(nc[i] / gc, char(i + 'a'));

}
