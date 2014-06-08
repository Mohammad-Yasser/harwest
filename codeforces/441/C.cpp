#include <bits/stdc++.h>
using namespace std;

int days[3003];

int main() {

    int n, m, k, curri = 1, currj = 1, d = 1;
    cin >> n >> m >> k;
    for (int i = 1; i < k; ++i) {
        cout << 2 << ' ' << curri << ' ' << currj;
        if (currj + d <= m && currj + d >= 1)
            currj += d;
        else
            d *= -1, ++curri;
        cout << ' ' << curri << ' ' << currj << '\n';
        if (currj + d <= m && currj + d >= 1)
            currj += d;
        else
            d *= -1, ++curri;
    }
    int rem = n * m - 2 * k + 2;
    cout << rem << ' ';
    while (rem--) {
        cout << curri << ' ' << currj << ' ';
        if (currj + d <= m && currj + d >= 1)
            currj += d;
        else
            d *= -1, ++curri;

    }

}
