#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    int n, k, mx = 1 << 25, ans = 1, mxt = 0, mn, af = 0, d = 0;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; cin >> a[i], ++i)
        ;
    for (int i = 1; i <= 1000; ++i) {
        mxt = 0;
        for (int j = 0; j < n; ++j)
            mxt += (a[j] != (i + k * j));
        if (mxt < mx) {
            mx = mxt;
            ans = i;
        }
    }

    cout << mx << endl;
    for (int i = 0; i < n; ++i) {
        if (a[i] > ans + k * i)
            cout << "- " << i + 1 << ' ' << a[i] - (ans + k * i) << endl;
        if (a[i] < ans + k * i)
            cout << "+ " << i + 1 << ' ' << ans + k * i - a[i] << endl;
    }
}
