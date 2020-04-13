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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);
  Long g = -1;
  for (auto& p : arr) {
    cin >> p.first >> p.second;
  }

  buildPrimeFactors(arr.back().first);
  buildPrimeFactors(arr.back().second);

  for (auto& g : prime_factors) {
    bool valid = true;
    for (auto& p : arr) {
      valid &= (p.first % g == 0 || p.second % g == 0);
    }
    if (valid) {
      cout << g << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}