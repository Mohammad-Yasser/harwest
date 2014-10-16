#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, ans = 0;
    while (cin >> t)
        ans += t;
    if (ans % 5 or !ans)
        cout << -1;
    else
        cout << ans / 5;

}
