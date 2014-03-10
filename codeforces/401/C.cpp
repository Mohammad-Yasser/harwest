#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    string s;
    if (m > 2 * n + 2 or n > m + 1) {
        cout << -1;
        return 0;
    }
    if (m > 2 * n) {
        s += "11";
        m -= 2;
    } else if (n > m) {
        s += "0";
        n--;
    } else {
        s += "1";
        m--;
    }
    while (n > 0 or m > 0) {
        if (s[s.size() - 1] == '0') {
            s += '1';
            m--;
        } else if (m > n && s[(int) s.size() - 2] == '0') {
            s += '1';
            m--;
        } else {
            s += '0';
            n--;
        }
    }
    cout << s;
}
