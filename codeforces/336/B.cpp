#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

int main() {
    int n, r;
    cin >> n >> r;
    long double ans = n * r * 2 + (n - 1) * (4 * r + 2 * r * sqrt(2));
    for (int i = 3; i <= n; ++i)
        ans += 4 * r * (n - i + 1) * (i - 2 + sqrt(2));
    cout << setprecision(11) << ans / n / n;
}
