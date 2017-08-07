#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 201;
const Long MX = 1e18 + 1;
const int LogMX = log(MX) / log(5) + 3;
const int M = 2 * N * LogMX + 5;

int dp[2][N][M];

int cnt5[N], cnt2[N];

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
        int leave = dp[!curr][rem][c];

        int new_cnt5 = max(0, c - M / 2) + cnt5[i];
        int new_cnt2 = max(0, M / 2 - c) + cnt2[i];

        int new_c = M / 2 + new_cnt5 - new_cnt2;
        new_c = max(new_c , 0);
        new_c = min(new_c , M - 1);
        
        int take = min(new_cnt5, new_cnt2) + dp[!curr][rem - 1][new_c];

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