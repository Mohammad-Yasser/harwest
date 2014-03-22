#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main() {
    int n[] = { 0, 0, 0 }, r;
    string s;
    cin >> s;
    while (cin >> s) {
        r = 0;
        for (int i = 0; i < s.size(); r += s[i] - '0', ++i)
            ;
        r %= 3;
        n[r]++;
    }
    cout << n[0] / 2 + min(n[1], n[2]);
}
