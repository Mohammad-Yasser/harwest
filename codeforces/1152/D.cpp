#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 1e3 + 3;
const int MOD = round(1e9 + 7);

Long memo[N][N][2];

Long solve(int existing, int yet, bool taken) {
  if (existing == 0 && yet == 0) return 0;
  Long& res = memo[existing][yet][taken];
  if (res != -1) return res;
  res = 0;

  if (taken) {
    if (existing > 0) {
      res = (res + solve(existing - 1, yet, false)) % MOD;
    }
    if (yet > 0) {
      res = (res + solve(existing + 1, yet - 1, false)) % MOD;
    }
  } else {
    if (existing > 0) {
      res = (res + 1 + solve(existing - 1, yet, true)) % MOD;
    }
    if (yet > 0) {
      res = (res + solve(existing + 1, yet - 1, false)) % MOD;
    }
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

  int n;
  cin >> n;

  memset(memo, -1, sizeof memo);
  cout << solve(0, n, false);

}
