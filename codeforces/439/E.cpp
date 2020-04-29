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

const int N = 2e5 + 5;
const int MOD = round(1e9 + 7);

vector<int> divs[N];
int fact[N];
int invFact[N];

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
  invFact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = 1LL * i * fact[i - 1] % MOD;
    invFact[i] = modInverse(fact[i]);
  }
}

void init() {
  buildFactorial();
  for (int i = 1; i < N; ++i) {
    for (int j = 2 * i; j < N; j += i) {
      divs[j].emplace_back(i);
    }
  }
}

int nCr(int n, int r) {
  int res = fact[n];
  res = 1LL * res * invFact[r] % MOD;
  res = 1LL * res * invFact[n - r] % MOD;
  return res;
}

int stars_and_bars(int n, int f) { return nCr(n - 1, f - 1); }

int memo[N];
int vis[N];
int v_id;
int f;

int dp(int n) {
  if (n < f) return 0;
  int& res = memo[n];
  if (vis[n] == v_id) return res;
  vis[n] = v_id;
  res = stars_and_bars(n, f);

  for (int d : divs[n]) {
    res = (res - dp(d)) % MOD;
  }
  res = (res + MOD) % MOD;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  init();
  int q;
  cin >> q;

  while (q--) {
    int n;
    cin >> n >> f;
    ++v_id;
    cout << dp(n) << endl;
  }
  return 0;
}
