#include <bits/stdc++.h>
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define getMSB(x) (__builtin_clzll(x))

typedef long long Long;
typedef unsigned long long ULong;
typedef vector<Long> Matrix;

const int N = 2e5 + 5;
const int M = 3;
const int MOD = round(1e9 + 7);

int cnt[M];
int memo[N][M];

int solve(int n, int m) {
  if (m < 0) m += M;
  if (n == 0) return m == 0;
  int& res = memo[n][m];
  if (res != -1) return res;
  res = 0;
  for (int i = 0; i < M; ++i) {
    res = (res + 1LL * cnt[i] * solve(n - 1, m - i)) % MOD;
  }
  return res;
}

int getCnt(int m, int x) {
  int res = x / M;
  if (m != 0 && m <= x % M) {
    ++res;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  memset(memo, -1, sizeof memo);
  int n, l, r;
  cin >> n >> l >> r;
  for (int i = 0; i < M; ++i) {
    cnt[i] = getCnt(i, r) - getCnt(i, l - 1);
  }
  cout << solve(n, 0);
}
