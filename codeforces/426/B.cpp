#include <bits/stdc++.h>

using namespace std;

int main() {
        ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    string arr[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = string(m, '0');
        for (int j = 0; j < m; cin >> arr[i][j], ++j)
            ;
    }
    int r = 2 * n;
    while (!((r / 2) % 2)) {
        r /= 2;
        for (int i = 0; i < n; i += r) {
            for (int a = i; a < i + r / 2; ++a)
                if (arr[a] != arr[i + r - a - 1])
                    goto rrr;
        }
        continue;
        rrr: cout << r;
        return 0;
    }
    cout <<  r/2;
}