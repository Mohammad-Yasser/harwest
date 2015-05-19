#include <bits/stdc++.h>
using namespace std;

int memo[100005][2], xs[100005], hs[100005], n, posLft[100005];

int DP(int idx, bool left) {
    if (idx == n - 1) return !left;
    int &ret = memo[idx][left];
    if (ret + 1) return ret;
    if (left) {
        int mx1 = DP(idx + 1, 1) + (xs[idx + 1] - hs[idx + 1] > xs[idx]);
        int mx2 = DP(idx + 1, 0);
        ret = max(mx1, mx2);
    }
    else {
        if (xs[idx] + hs[idx] < xs[idx + 1]) {
            int posL = lower_bound(xs, xs + n, xs[idx] + hs[idx]) - xs;
            if (xs[idx] + hs[idx] >= xs[posL] - hs[posL]) posL = posLft[posL];
            ret = 1 + max(1 + DP(posL, 1), DP(idx + 1, 0));
        }
        else
            ret = DP(idx + 1, 0);
    }
    return ret;
}

int main() {
    memset(memo, -1, sizeof memo);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> xs[i] >> hs[i];
    posLft[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        if (xs[i + 1] - hs[i + 1] > xs[i])
            posLft[i] = i + 1;
        else
            posLft[i] = posLft[i + 1];
    }
    cout << 1 + DP(0, 1);

}
