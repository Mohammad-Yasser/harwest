#include <bits/stdc++.h>
using namespace std;

int days[3003];
int n, m, k, curri = 1, currj = 1, d = 1;

bool fn() {
    cout << curri << ' ' << currj << ' ';
    if (currj + d <= m && currj + d >= 1)
        currj += d;
    else
        d *= -1, ++curri;
    return 1;
}
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i < k && cout << "2 " && fn() && fn(); cout << '\n', ++i)
        ;
    n = n * m - 2 * k + 2;
    cout << n << ' ';
    while (n-- && fn())
        ;
}
