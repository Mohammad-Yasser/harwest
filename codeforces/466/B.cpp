#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    long long n, a, b, area, ans, bns;
    cin >> n >> a >> b;
    ans = a, bns = b;
    n *= 6;
    area = LLONG_MAX;
    bool swp = 0;
    if (a > b) {
        swap(a, b);
        swp = 1;
    }
    if (a * b >= n)
        area = a * b;
    for (; (a - 1) * (a - 1) <= n; ++a) {
        long long tmp = (n / a + bool(n % a));
        if (a * tmp <= area && tmp >= b)
            ans = a, bns = tmp, area = ans * bns;
    }

    if (swp)
        swap(ans, bns);
    cout << area << '\n' << ans << ' ' << bns;

}
