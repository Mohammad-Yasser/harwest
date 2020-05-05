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

template <typename T>
void minimize(T& x, T y) {
  x = min(x, y);
}

template <typename T>
void maximize(T& x, T y) {
  x = max(x, y);
}

typedef long long Long;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  string res;
  while (t--) {
    int n;
    cin >> n;
    res = "1" + string(1e5, '3');
    for (int i = res.size(); i > 2; --i) {
      Long cnt = 1LL * (i - 1) * (i - 2) / 2;
      while (cnt <= n) {
        n -= cnt;
        res.insert(res.begin() + i, '7');
      }
    }
    res.resize(1e5);
    cout << res << endl;
  }
  return 0;
}
