#include <bits/stdc++.h>
using namespace std;

int main() {
    long long curr = 0, ans[5];
    int n, cost[5];
    cin >> n;
    int p[n];
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < 5; ++i)
        cin >> cost[i], ans[i] = 0;
    for (int i = 0; i < n; ++i) {
        curr += p[i];
        for (int ind = 4; ind >= 0; --ind)
            ans[ind] += curr / cost[ind], curr %= cost[ind];
    }
    for (int i = 0; i < 5; ++i)
        cout << ans[i] << "\n "[i < 4];
    cout << curr;
}
