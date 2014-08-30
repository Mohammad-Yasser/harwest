#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    int n, s, cnt;
    cin >> n >> s;
    int mx = 0;
    bool b = 0;
    while (cin >> n >> cnt) {
        b |= (n + bool(cnt) <= s);
        if (n < s && cnt)
            mx = max(mx, 100 - cnt);
    }
    cout << (b ? mx : -1);

}
