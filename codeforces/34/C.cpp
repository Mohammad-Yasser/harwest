#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int sti(string s) {
    stringstream ss;
    int i;
    ss << s;
    ss >> i;
    return i;
}

int main() {
    ios::sync_with_stdio(0);
    bool b[1003];
    fill(b, b + 1003, 0);
    char c;
    string s;
    while (cin >> c) {
        if (c == ',') {
            b[sti(s)] = 1;
            s.clear();
        } else
            s += c;
    }
    b[sti(s)] = 1;
    int i = 0;
    for (; i < 1003 && !b[i]; ++i)
                ;
    while (i < 1003) {

        cout << i;
        if (b[++i]) {
            cout << '-';
            for (; i < 1003 && b[i]; ++i)
                ;
            cout << i - 1;

        }
        for (; i < 1003 && !b[i]; ++i)
                    ;
        if (i<1003)
        cout << ',';

    }

}
