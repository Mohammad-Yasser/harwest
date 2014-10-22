#include <bits/stdc++.h>

using namespace std;

int main() {

    double ans = 0;
    int n, m;
    cin >> m >> n;
    ans = m;
    for (int i = 1; i < m; ++i)
        ans -= pow((double) (m - i) / m, n);
    cout << fixed << setprecision(11) << ans;
}
