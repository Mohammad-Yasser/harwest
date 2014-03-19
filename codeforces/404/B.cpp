#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    double n, a, d, i;
    cin >> a >> d >> n;
    d = fmod(d, 4 * a);
    i = d;
    for (int j = 0; j < n; ++j) {
        if (i > 4 * a)
            i -= 4 * a;
        if (i <= a)
            cout << fixed << i << ' ' << fixed << 0 << endl;
        else if (i <= 2 * a)
            cout << fixed << a << ' ' << fixed << i - a << endl;
        else if (i <= 3 * a)
            cout << fixed << 3 * a - i << ' ' << fixed << a << endl;
        else
            cout << fixed << 0 << ' ' << fixed << 4 * a - i << endl;
        i += d;
    }
}
