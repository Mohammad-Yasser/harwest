#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const short N = 201;
const Long MX = 1e18 + 1;
const short LogMX = log(MX) / log(5) + 3;
const short M = N * LogMX;

short dp[2][N][M];

short cnt5[N], cnt2[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    Long x;
    cin >> x;

    while (x % 5 == 0) {
      ++cnt5[i];
      x /= 5;
    }

    while (x % 2 == 0) {
      ++cnt2[i];
      x /= 2;
    }
  }

  memset(dp, numeric_limits<char>::min(), sizeof dp);

  short ans = 0;
  for (int i = 0; i < n; ++i) {
    bool curr = i & 1;
    dp[!curr][0][0] = 0;

    for (int rem = 1; rem < N; ++rem) {
      for (int c = 0; c < M; ++c) {
        short leave = dp[!curr][rem][c];

        short take = dp[!curr][rem - 1][max(short(0), short(c - cnt5[i]))]
          + cnt2[i];

        dp[curr][rem][c] = max(leave, take);
      }
    }

    for (short rem = 0; rem < N; ++rem) {
      for (short c = 0; c < M; ++c) {
        dp[!curr][rem][c] = dp[curr][rem][c];
        ans = max(ans, min(c, dp[curr][k][c]));
      }
    }
  }

  cout << ans;

}
