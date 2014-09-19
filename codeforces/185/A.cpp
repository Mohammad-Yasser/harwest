#include <bits/stdc++.h>
using namespace std;
long long pw(long long n, long long p) {
    n %= 1000000007;
    if (!p)
        return 1;
    long long ans = (n * n) % 1000000007;
    if (p % 2)
        return (n * ((pw(ans, p / 2)) % 1000000007)) % 1000000007;
    else
        return pw(n * n, p / 2) % 1000000007;
}
int main() {
    long long n;
    cin >> n;
    if (!n) {
        cout << 1;
        return 0;
    }
    long long ans = pw(2, n - 1) % 1000000007;
    cout << (ans * (1 + 2 * ans)) % 1000000007;
}
