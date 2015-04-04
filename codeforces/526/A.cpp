#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    string s;
    cin >> n >> s;
    bool b = 0;
    for (int i = 1; i < 101; ++i)
        for (int j = 0; j < n; ++j) {
            int g = 0;
            for (int t = j; t < n && s[t] == '*'; t += i, ++g)
                ;
            b |= (g >= 5);
        }
    cout << (b ? "yes" : "no") << endl;
}