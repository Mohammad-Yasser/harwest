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

// f(a, k) = pa * f(a + 1, k) + pb * (f(a, k - a) + a)

// s = summation (pa^i * i)
//   = pa / (1 - pa) + pa * s
//   ^ Remove 1 from each i, divide by pa, and you'll return to the same state.
// s * (1 - pa) = pa / pb
// s = pa / (pb * pb)

// a >= k:
// First way:
// f(a) = pa * f(a + 1) + pb * a
//      = pb * summation (pa^i * (a+i))
//      = pb * (a * summation (pa^i) + summation (pa^i * i))
//      = pb * (a / pb + pa / (pb^2))
//      = a + pa / pb
//
// Second Way:
// Expected number of trials before having b is (1 / pb - 1),
// hence f(a) = a + 1 / pb - 1

// f(0, k) = x + pb * f(0, k)
// f(0, k) * (1 - pb) = x
// f(0, k) = x / pa

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

int memo[N][N];
int pa, pb;
int f(int a, int k) {
  if (k <= 0) return 0;
  if (a >= k) return (a + modInverse(pb) - 1) % MOD;
  int& res = memo[a][k];
  if (res != -1) return res;

  res = 1LL * pa * f(a + 1, k) % MOD;
  if (a != 0) {
    res = (res + 1LL * pb * (f(a, k - a) + a)) % MOD;
  } else {
    res = 1LL * res * modInverse(pa) % MOD;
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

  int k;
  cin >> k >> pa >> pb;
  int ps = pa + pb;
  pa = 1LL * pa * modInverse(ps) % MOD;
  pb = 1LL * pb * modInverse(ps) % MOD;
  memset(memo, -1, sizeof memo);
  cout << f(0, k) << endl;

  return 0;
}