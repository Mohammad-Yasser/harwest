#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll a, b;
    cin >> a >> b;

    ll curr = 2, ans = 0;
    while (curr <= b) {
        if (curr >= a) ++ans;
        if (curr == b) break ;
        if (!(curr & 1)) {
            curr |= 1;
            for (int i = 62;; --i)
                if (curr & (1ULL << i)) {
                    curr |= 1ULL << (i + 1);
                    curr ^= 1ULL << i;
                    break;
                }
        }
        else {
            for (int i = 1;; ++i)
                if (!(curr & (1ULL << i))) {
                    curr |= 1ULL << i;
                    curr ^= 1ULL << (i - 1);
                    break;
                }
        }
    }
    cout << ans;
}
