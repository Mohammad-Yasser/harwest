#include <bits/stdc++.h>
using namespace std;
string dtb(int n) {
    string s;
    while (n) {
        s += (n % 2) + '0';
        n /= 2;
    }
    return  s+string(21 - s.size(), '0') ;
}
int main() {
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    string arr[m + 1];
    for (int i = 0; i <= m; ++i)
        cin >> n, arr[i] = dtb(n);
    for (int i = 0; i < m; ++i) {
        int diff = 0;
        for (int j = 0; j < arr[i].size(); ++j)
            diff += arr[i][j] != arr[m][j];
        ans += diff <= k;

    }
    cout << ans ;
}
