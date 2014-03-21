#include <bits/stdc++.h>

using namespace std;

int btd(string s) {
    int b = 1;
    int t = 0;
    for (int i = 0; i < s.size(); ++i) {
        t += (s[i] - '0') * b;
        b *= 2;
        b %= (int) 1e6 + 3;
        t %= (int) 1e6 + 3;
    }
    return t;

}

int main() {
    map<char, string> mb;
    mb['>'] = "1000";
    mb['<'] = "1001";
    mb['+'] = "1010";
    mb['-'] = "1011";
    mb['.'] = "1100";
    mb[','] = "1101";
    mb['['] = "1110";
    mb[']'] = "1111";
    string s;
    char c;
    while (cin >> c)
        s += mb[c];
    reverse(s.begin(), s.end());
    cout << btd(s);

}
