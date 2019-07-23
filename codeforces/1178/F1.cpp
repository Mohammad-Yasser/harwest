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

const int N = 505;
const int MOD = 998244353;

int memo[N][N];
int arr[N];

int getMin(int l, int r) {
  int res = l;
  for (int i = l; i <= r; ++i) {
    if (arr[i] < arr[res]) {
      res = i;
    }
  }
  return res;
}

int solve(int l, int r) {
  if (l > r) return 0;
  if (l == r) return 1;

  int& res = memo[l][r];
  if (res != -1) return res;
  int mn = getMin(l, r);

  if (mn == l) {
    res = 2 * solve(l + 1, r);
    for (int i = l + 1; i < r; ++i) {
      res = (res + 1LL * solve(l + 1, i) * solve(i + 1, r)) % MOD;
    }
    return res;
  }

  if (mn == r) {
    res = 2 * solve(l, r - 1);
    for (int i = r - 1; i > l; --i) {
      res = (res + 1LL * solve(i, r - 1) * solve(l, i - 1)) % MOD;
    }
    return res;
  }

  int a = 2 * solve(l, mn - 1);
  int b = 2 * solve(mn + 1, r);

  for (int i = mn - 1; i > l; --i) {
    a = (a + 1LL * solve(l, i - 1) * solve(i, mn - 1)) % MOD;
  }

  for (int i = mn + 1; i < r; ++i) {
    b = (b + 1LL * solve(i + 1, r) * solve(mn + 1, i)) % MOD;
  }

  res = 1LL * a * b % MOD;

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
  cin >> n >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  memset(memo, -1, sizeof memo);

  cout << solve(1, n) << endl;
}
