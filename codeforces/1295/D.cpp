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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<Long> getDivisors(Long n) {
  vector<Long> res;
  for (Long i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      res.emplace_back(i);
      if (i != n / i) {
        res.emplace_back(n / i);
      }
    }
  }
  sort(res.begin(), res.end());
  return res;
}

gp_hash_table<Long, int> memo;

int mobius(Long n) {
  if (n == 1) return 1;
  if (memo[n] != 0) return memo[n];
  Long first = 2;
  while (first * first <= n && n % first != 0) {
    ++first;
  }
  if (n % first == 0) {
    if ((n / first) % first == 0) return memo[n] = 0;
    return memo[n] = -mobius(n / first);
  } else {
    return memo[n] = -1;
  }
}

Long solve(Long a, Long m) {
  Long g = __gcd(a, m);
  auto divs = getDivisors(m);
  Long res = 0;
  for (auto& div : divs) {
    if (div % g == 0) {
      res += mobius(div / g) * (m - 1) / div;
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

  int t;
  cin >> t;

  while (t--) {
    Long a, m;
    cin >> a >> m;

    cout << solve(a, m) << endl;
  }
  return 0;

}
