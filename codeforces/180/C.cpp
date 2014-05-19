#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int ul = 0, ll = 0, lr = 0, ur = 0;
    for (int i = 0; i < s.size(); ur += isupper(s[i]),++i)
        ;
    lr=s.size()-ur ;
    int mn = ur;
    for (int i = 0; i < s.size(); ++i) {
        if (isupper(s[i]))
            ul++, ur--;
        else
            ll++, lr--;
        mn = min(mn, ll + ur);
    }
    cout << mn;
}
