#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    long long n, k, sm = 0, lw = 0, hg, md;
    cin >> n >> k;
    --k;
    hg = k;
    while (lw < hg) {
        md = (lw + hg) / 2;
        if (md * (2 * k - md + 1) / 2 + 1 < n)
            lw = md + 1;
        else
            hg = md;
    }
    if (lw * (2 * k - lw + 1) / 2 + 1 >= n)
        cout << lw;
    else
        cout << -1;

}
