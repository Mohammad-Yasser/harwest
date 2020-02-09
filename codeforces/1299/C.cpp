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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5 + 5;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  vector<int> v(n);

  for (auto& x : v) {
    cin >> x;
  }

  vector<pair<int, Long>> res;

  for (int i = n - 1; i >= 0; --i) {
    res.emplace_back(1, v[i]);

    while (res.size() > 1) {
      Long a, b, c, d;
      tie(a, b) = res.back();
      tie(c, d) = res[res.size() - 2];
      if (a * d > c * b) break;
      res.pop_back();
      res.back().first += a;
      res.back().second += b;
    }
  }

  while (!res.empty()) {
    double curr = (double) res.back().second / res.back().first;
    while (res.back().first--) {
      cout << fixed << setprecision(10) << curr << endl;
    }
    res.pop_back();
  }

  cout << endl;

  return 0;
}
