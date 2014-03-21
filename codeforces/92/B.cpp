#include <bits/stdc++.h>
using namespace std;
int cnt(string s) {
    int t = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < (int) s.size() - 1; ++i)
        if (s[i] == '1') {
            ++t;
            for (; i < (int) s.size() && s[i] == '1'; ++t, ++i)
                ;
            s[i] = '1';
            --i;
        } else
            ++t;
    return t;
}
int main() {
    string s;
    cin >> s;
    cout << cnt(s);
}
