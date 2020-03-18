#ifndef Local
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

// gp_hash_table<int, int> table;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1003;
const int MOD = 1000000007;
int memo[N][N];
int nCr[N][N];

void buildnCr() {
  for (int n = 0; n < N; ++n) {
    for (int r = 0; r < N; ++r) {
      if (n == r || r == 0) {
        nCr[n][r] = 1;
        continue;
      }
      if (r > n) {
        nCr[n][r] = 0;
        continue;
      }
      if (r == 1 || r == n - 1) {
        nCr[n][r] = n;
        continue;
      }
      nCr[n][r] = (nCr[n - 1][r - 1] + nCr[n - 1][r]) % MOD;
    }
  }
}

int n;
int arr[N];
int suff_sum[N];

int solve(int ind, int slots) {
  if (slots < 0 || slots >= N) return 0;
  if (ind == n) return slots == 0;
  int& res = memo[ind][slots];
  if (res != -1) return res;

  res = 0;
  slots = max(slots, arr[ind] - 1);
  while (slots <= suff_sum[ind]) {
    res = (res
      + 1LL * nCr[slots][arr[ind] - 1] * solve(ind + 1, slots - arr[ind] + 1))
      % MOD;
    ++slots;
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

  buildnCr();

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    suff_sum[i] = arr[i] - 1;
  }
  for (int i = n - 1 ; i >= 0 ; --i) {
    suff_sum[i] += suff_sum[i + 1];
  }

  memset(memo, -1, sizeof memo);
  cout << solve(0, 0) << endl;

}
