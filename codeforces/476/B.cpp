#include <bits/stdc++.h>
using namespace std;

int main() {
    int fct[11];
    fct[0] = 1;
    for (int i = 1; i < 11; ++i)
        fct[i] = i * fct[i - 1];
    string s1, s2;
    cin >> s1 >> s2;
    int s = 0, p = 0, q = 0;
    for (int i = 0; i < s1.size(); ++i)
        s += (s1[i] == '+') - (s1[i] == '-'), p += (s2[i] == '+')
                - (s2[i] == '-'), q += (s2[i] == '?');
    cout << fixed << setprecision(9)
            << fct[q] / fct[(q + s - p) / 2] / fct[q - (q + s - p) / 2]
                    / pow(2, q);

}