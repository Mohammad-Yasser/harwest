#include <bits/stdc++.h>
using namespace std;

int days[3003];

int main() {

    int n, v, tmp, ans = 0;
    cin >> n >> v;
    while (cin >> n >> tmp)
        days[n] += tmp;
    for (int i = 1; i <= 3003; ++i)
        ans += min(days[i - 1], v) + min(days[i], v - min(days[i - 1], v)), days[i] -=
                min(days[i], v - min(days[i - 1], v));
    cout << ans;
}
