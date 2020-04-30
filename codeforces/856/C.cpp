#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
typedef vector<int> vi;

const int N = 2003;
const int MOD = 998244353;
const int A = 11;

int fact[N];
int inv_fact[N];

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
  for (int i = 1; i < N; ++i) {
    fact[i] = 1LL * i * fact[i - 1] % MOD;
    inv_fact[i] = modInverse(fact[i]);
  }
}

int memo[N][N][A];
int vis[N][N][A];
int vid;

int solve_even(int ind, int cnt_odd, int cnt_even, int m,
               const vector<int>& v) {
  if (ind == v.size()) {
    return m == 0;
  }
  int& res = memo[ind][cnt_odd][m];
  if (vis[ind][cnt_odd][m] == vid) return res;
  vis[ind][cnt_odd][m] = vid;
  res = 1LL * cnt_even *
        solve_even(ind + 1, cnt_odd, cnt_even + 1, (m + v[ind]) % 11, v) % MOD;

  res = (res + 1LL * cnt_odd *
                   solve_even(ind + 1, cnt_odd + 1, cnt_even,
                              (m - v[ind] + 11) % 11, v)) %
        MOD;

  return res;
}

int solve_odd(int ind, int cnt_even, int m, const vector<int>& v) {
  if (ind == v.size()) {
    return m == 0 && cnt_even == (v.size()) / 2;
  }
  int& res = memo[ind][cnt_even][m];
  if (vis[ind][cnt_even][m] == vid) return res;
  vis[ind][cnt_even][m] = vid;
  res = solve_odd(ind + 1, cnt_even + 1, (m + v[ind]) % 11, v);
  res = (res + solve_odd(ind + 1, cnt_even, (m - v[ind] + 11) % 11, v)) % MOD;
  return res;
}

int getLength(int x) {
  if (x == 0) return 0;
  return 1 + getLength(x / 10);
}

int even_res[11];
int odd_res[11];

int solve(vector<int>& v) {
  ++vid;
  vector<int> even, odd;

  for (int x : v) {
    if (getLength(x) & 1) {
      odd.emplace_back(x % 11);
    } else {
      even.emplace_back(x % 11);
    }
  }

  int res = 0;
  for (int i = 0; i < 11; ++i) {
    even_res[i] =
        solve_even(0, (1 + odd.size()) / 2, 1 + odd.size() / 2, i, even);
  }
  ++vid;
  for (int i = 0; i < 11; ++i) {
    odd_res[i] = solve_odd(0, 0, (11 - i) % 11, odd);
  }
  for (int i = 0; i < 11; ++i) {
    res = (res + 1LL * even_res[i] * odd_res[i]) % MOD;
  }

  res = 1LL * res * fact[odd.size() / 2] % MOD;
  res = 1LL * res * fact[(odd.size() + 1) / 2] % MOD;
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
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x : v) {
      cin >> x;
    }
    cout << solve(v) << endl;
  }

  return 0;
}
