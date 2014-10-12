#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    for (int i = 1; i < b; ++i)
        ans = (ans + ((a * (a + 1) / 2) % 1000000007) * ((i * b) % 1000000007)
                + a * i)% 1000000007;
    cout << ans;

}
