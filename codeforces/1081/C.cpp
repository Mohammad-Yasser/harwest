//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse4.1,sse4.2,ssse3,sse3,sse2,sse,avx")
//#pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = 2003;
const int MOD = 998244353;

Long memo[N][N];

int m;

Long solve(int n, int k) {
  if (k < 0) return 0;
  if (n == 1) return k == 0;
  Long& res = memo[n][k];
  if (res != -1) return res;

  res = (1LL * (m - 1) * solve(n - 1, k - 1)) % MOD;
  res = (res + solve(n - 1, k)) % MOD;

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
  int n, k;
  cin >> n >> m >> k;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      solve(i, j);
    }
  }

  cout << 1LL * m * solve(n, k) % MOD;

}
