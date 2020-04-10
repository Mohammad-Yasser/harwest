#ifndef Local
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
typedef vector<int> vi;

vector<Long> prime_factors;

void buildPrimeFactors(Long d) {
  for (Long i = 2; i * i <= d; ++i) {
    if (d % i != 0) continue;
    prime_factors.emplace_back(i);
    while (d % i == 0) {
      d /= i;
    }
  }
  if (d != 1) {
    prime_factors.emplace_back(d);
  }
}

int countDivs(Long d) {
  int res = 0;
  for (int i = 1; 1LL * i * i <= d; ++i) {
    if (d % i == 0) {
      ++res;
      res += (i != d / i);
    }
  }
  return res;
}

const int MOD = 998244353;
const int FN = 77;
int fact[FN];

void buildFactorial() {
  fact[0] = 1;
  for (int i = 1; i < FN; ++i) {
    fact[i] = 1LL * i * fact[i - 1] % MOD;
  }
}

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

int getShortestPaths(Long d) {
  map<Long, int> cnt_prime_factors;
  int sum = 0;
  for (auto& prime_factor : prime_factors) {
    while (d % prime_factor == 0) {
      ++cnt_prime_factors[prime_factor];
      ++sum;
      d /= prime_factor;
    }
  }
  int res = fact[sum];
  for (auto& p : cnt_prime_factors) {
    res = 1LL * res * modInverse(fact[p.second]) % MOD;
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

  Long d;
  cin >> d;
  buildPrimeFactors(d);
  buildFactorial();

  int q;
  cin >> q;

  while (q--) {
    Long a, b;
    cin >> a >> b;
    Long g = __gcd(a, b);
    int res = getShortestPaths(a / g);
    res = 1LL * res * getShortestPaths(b / g) % MOD;
    cout << res << endl;
  }

  return 0;
}