#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main() {
    ull n, q, l = 0, r = 0;
    cin >> n;
    ull arr[n];
    ull arn[100003];
    fill(arn, arn + 100003, 0);
    for (int i = 0; i < n; cin >> arr[i++])
        ;
    cin >> q;
    while (cin >> q)
        ++arn[q];
    ;
    for (int i = 0; i < n; ++i) {
        l += arn[arr[i]] * (i + 1);
        r += arn[arr[i]] * (n - i);
    }
    cout << l << ' ' << r;
}
