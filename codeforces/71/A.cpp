#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;
    cin >> s;
    while (cin >> s)
        if (s.size() <= 10)
            cout << s << '\n';
        else
            cout << s[0] << s.size() - 2 << s[s.size() - 1] << '\n';

}
