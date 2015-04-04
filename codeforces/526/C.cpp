#include <bits/stdc++.h>
using namespace std;

int main() {
    long long c, hr, hb, wr, wb, mx = 0;
    cin >> c >> hr >> hb >> wr >> wb;
    for (int i = 0; i < 2; ++i) {
        long long f = c / wr;
        for (long long i = max(0LL, f - 10000000); i <= f; ++i)
            mx = max(i * hr + (c - i * wr) / wb * hb, mx);
        swap(hr, hb);
        swap(wr, wb);
    }
    cout << mx;
}
