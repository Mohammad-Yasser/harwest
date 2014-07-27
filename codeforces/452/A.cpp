#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;
    cin >> s >> s;
    string n[8] = { "vaporeon", "jolteon", "flareon", "espeon", "umbreon",
            "leafeon", "glaceon", "sylveon" };
    for (int i = 0; i < 8; ++i) {
        if (n[i].size() == s.size()) {
            bool b = 1;
            for (int j = 0; j < s.size();
                    b &= (s[j] == n[i][j] or s[j] == '.'), ++j)
                ;
            if (b)
                cout << n[i];
        }

    }

}
