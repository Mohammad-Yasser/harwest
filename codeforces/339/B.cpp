#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 0, n, m, st = 1;
    cin >> n >> m;
    while (cin >> m)
        ans += (m - st + n) % n, st = m;
    cout << ans;
}
