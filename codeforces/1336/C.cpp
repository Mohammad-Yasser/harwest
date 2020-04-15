#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define all(v) begin(v), end(v)

typedef long long Long;
typedef vector<int> vi;

const int N = 3003;
const int MOD = 998244353;

string t, s;

int dp[2][N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> s >> t;
  dp[0][t.size()] = 2;
  int res = 0;
  for (int i = 0; i < t.size(); ++i) {
    if (t[i] == s[0]) {
      dp[0][i] = 2;
    }
  }

  bool curr = 0;
  for (int i = 1; i < s.size(); ++i) {
    bool nxt = !curr;
    memset(dp[nxt], 0, sizeof dp[nxt]);
    if (i >= t.size()) {
      res = (res + dp[curr][0]) % MOD;
    }
    // Back
    for (int j = 0; j < t.size(); ++j) {
      if (t[j] == s[i]) {
        dp[nxt][j] = dp[curr][j + 1];
      }
    }
    dp[nxt][t.size()] = dp[curr][t.size()];

    // Front
    for (int j = 0; j <= t.size(); ++j) {
      if (j + i >= t.size()) {
        dp[nxt][j] = (dp[nxt][j] + dp[curr][j]) % MOD;
      } else if (t[j + i] == s[i]) {
        dp[nxt][j] = (dp[nxt][j] + dp[curr][j]) % MOD;
      }
    }
    curr ^= 1;
  }
  res = (res + dp[curr][0]) % MOD;
  cout << res << endl;
  return 0;
}
