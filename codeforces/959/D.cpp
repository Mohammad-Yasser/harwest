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

const int N = 1e7 + 5;
int n;

vector<int> primes;
bool is_prime[N];

void build() {
  fill(is_prime, is_prime + N, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < N; ++i) {
    if (!is_prime[i]) continue;
    primes.emplace_back(i);
    for (int j = 2 * i; j < N; j += i) {
      is_prime[j] = false;
    }
  }
}

vector<int> prime_factors[N];

vector<int> getPrimeFactors(int x) {
  int n = x;
  if (!prime_factors[x].empty()) return prime_factors[x];
  for (int p : primes) {
    if (1LL * p * p > x) break;
    if (x % p != 0) continue;
    prime_factors[n].emplace_back(p);
    while (x % p == 0) x /= p;
  }
  if (x != 1) prime_factors[n].emplace_back(x);
  return prime_factors[n];
}

bool vis[N];
int a[N];

bool can(const vector<int>& factors) {
  for (int x : factors) {
    if (vis[x]) return false;
  }
  for (int x : factors) {
    vis[x] = true;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  build();

  cin >> n;
  vector<int> res;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    auto factors = getPrimeFactors(x);
    if (can(factors)) {
      res.emplace_back(x);
      continue;
    }
    for (int j = x; j < N; ++j) {
      if (can(getPrimeFactors(j))) {
        res.emplace_back(j);
        break;
      }
    }
    int rem = n - i - 1;
    for (int j : primes) {
      if (rem == 0) break;
      if (!vis[j]) {
        res.emplace_back(j);
        --rem;
      }
    }
    break;
  }

  for (int x : res) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
