#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
typedef long long Long;
typedef double Double;

const int N = 1e3 + 5;
const int MOD = round(1e9 + 7);

int memo_k[N];
int getK(int n) {
  if (n == 1) return 0;
  int& res = memo_k[n];
  if (res != -1) return res;
  return res = 1 + getK(popCnt(n));
}

int memo_w[N][N][2];
string s;
int solve(int ind, int ones, bool less) {
  if (ones < 0) return 0;
  if (ind == s.size()) return ones == 0;
  int& res = memo_w[ind][ones][less];
  if (res != -1) return res;
  res = 0;
  if (less) {
    res = solve(ind + 1, ones - 1, true);
    res = (res + solve(ind + 1, ones, true)) % MOD;
  } else {
    if (s[ind] == '1') {
      res = (res + solve(ind + 1, ones - 1, false)) % MOD;
      res = (res + solve(ind + 1, ones, true)) % MOD;
    } else {
      res = (res + solve(ind + 1, ones, false)) % MOD;
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

  memset(memo_k, -1, sizeof memo_k);
  memset(memo_w, -1, sizeof memo_w);

  cin >> s;
  int k;
  cin >> k;
  if (k == 0) {
    cout << 1 << endl;
    return 0;
  }
  int res = 0;
  for (int i = 1; i <= s.size(); ++i) {
    if (getK(i) == k - 1) {
      res = (res + solve(0, i, false)) % MOD;
      if (i == 1) {
        res = (res + MOD - 1) % MOD;
      }
    }
  }
  cout << res << endl;

  return 0;
}