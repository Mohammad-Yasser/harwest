#include <bits/stdc++.h>
using namespace std;

int main() {
    int fct[30];
    fct[0] = 1;
    for (int i = 1; i < 30; ++i)
        fct[i] = i * fct[i - 1];
    string s1, s2;
    cin >> s1 >> s2;
    int s = 0, p = 0, q = 0;
    for (int i = 0; i < s1.size(); ++i)
        s += (s1[i] == '+') - (s1[i] == '-'), p += (s2[i] == '+')
                - (s2[i] == '-'), q += (s2[i] == '?');
    if (((q + s - p) & 1) or q - (q + s - p) / 2 < 0)
        cout << fixed << setprecision(9) << 0.0;
    else
        cout << fixed << setprecision(9)
                << fct[q] / fct[(q + s - p) / 2] / fct[q - (q + s - p) / 2]
                        / (double) (round(pow(2, q)));

}