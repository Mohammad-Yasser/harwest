#include <bits/stdc++.h>
using namespace std;

int b[101][2];
int n, k, d;
int rec(int sm, int mx) {
    if (b[sm][mx >= d] + 1)
        return b[sm][mx >= d];
    if (sm == n)
        return mx >= d;
    int ways = 0;
    for (int i = 1; i <= k; ++i)
        if (sm + i <= n)
            ways += rec(sm + i, max(mx, i)) % 1000000007, ways %= 1000000007;
    ways %= 1000000007;
    b[sm][mx >= d] = ways;
    return ways;

}

int main() {
    ios_base::sync_with_stdio(0);
    for (int i=0;i<101;b[i][0]=b[i][1]=-1,++i);
    cin >> n >> k >> d;
    cout << rec(0, 0) % 1000000007;
}
