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
typedef long double Double;

const int N = 500005;

const int MOD = 998244353;
const int FN = N;
int fact[FN];
int inv_fact[FN];

int power(int base, int p) {
  if (p == 0) return 1;
  int res = power(base, p / 2);
  res = 1LL * res * res % MOD;
  if (p & 1) {
    res = 1LL * res * base % MOD;
  }
  return res;
}

int modInverse(int x) { return power(x, MOD - 2); }

void buildFactorial() {
  fact[0] = 1;
  inv_fact[0] = 1;
  for (int i = 1; i < FN; ++i) {
    fact[i] = 1LL * i * fact[i - 1] % MOD;
    inv_fact[i] = modInverse(fact[i]);
  }
}

int nCr(int n, int r) {
  if (n < r) return 0;
  int res = fact[n];
  res = 1LL * res * inv_fact[r] % MOD;
  res = 1LL * res * inv_fact[n - r] % MOD;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  buildFactorial();

  int n, k;
  cin >> n >> k;

  int res = 0;
  for (int i = 1; i <= n; ++i) {
    int cnt = n / i - 1;
    res = (res + nCr(cnt, k - 1)) % MOD;
  }

  cout << res << endl;

  return 0;
}