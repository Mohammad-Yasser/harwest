#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k, ans = 0;
    cin >> n >> k;
    while (cin >> n)
        ans += max(n % k, n - 3 * k);
    cout << ans;
}
