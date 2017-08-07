#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const short N = 201;
const Long MX = 1e18 + 1;
const short LogMX = log(MX) / log(5) + 3;
const short M = 2 * N * LogMX + 5;

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

  for (int i = 0; i < n; ++i) {
    bool curr = i & 1;
    for (int rem = 1; rem < N; ++rem) {
      for (int c = 0; c < M; ++c) {
        short leave = dp[!curr][rem][c];

        short new_cnt5 = max((short)0, short(c - M / 2)) + cnt5[i];
        short new_cnt2 = max((short)0, short(M / 2 - c)) + cnt2[i];

        short new_c = M / 2 + new_cnt5 - new_cnt2;
        new_c = max(new_c , short(0));
        new_c = min(new_c , short(M - 1));
        
        short take = min(new_cnt5, new_cnt2) + dp[!curr][rem - 1][new_c];

        dp[curr][rem][c] = max(leave, take);
      }
    }

    for (int rem = 1; rem < N; ++rem) {
      for (int c = 0; c < M; ++c) {
        dp[!curr][rem][c] = dp[curr][rem][c];
      }

    }
  }

  cout << dp[~n & 1][k][M / 2];

}