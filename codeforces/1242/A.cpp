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

vector<Long> getPrimeFactors(Long n) {
  vector<Long> res;

  for (int i = 2; 1LL * i * i <= n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n != 1) {
    res.push_back(n);
  }
  return res;
}

Long solve(Long n) {
  auto prime_factors = getPrimeFactors(n);
  if (prime_factors.size() == 1) {
    return prime_factors[0];
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  Long n;
  cin >> n;
  cout << solve(n) << endl;

}
