#include <bits/stdc++.h>

using namespace std;
typedef long long Long;

const int N = 3e5 + 5;
const int MX = 1e8;
const int M = MX / N;

int a[N];

int n;


// Didn't prove that, and think it'll get WA.


int memo[2][M];

int main() {
#ifdef Local
    freopen("test.in", "r", stdin);
#endif

    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);


    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] /= 100;
    }


    for (int ind = n - 1; ind >= 0; --ind) {
        for (int card = 0; card < M; ++card) {
            bool b = ind & 1;
            int &res = memo[b][card];
            res = INT_MAX;
            int nxt_card = min(M - 1, card + a[ind] / 10);
            res = min(res, a[ind] + memo[!b][nxt_card]);
            int use = min(card, a[ind]);
            nxt_card = min(M - 1, card - use);
            res = min(res, a[ind] - use + memo[!b][nxt_card]);
        }
    }

    cout << memo[0][0] * 100;
}