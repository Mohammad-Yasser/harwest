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
    int n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);
    if (m == 1) {
      cout << 1 << endl;
      continue;
    }
    if (n == 1) {
      cout << (m + 1) / 2 << endl;
      continue;
    }
    int res = n / 2 * m + (n % 2) * (m + 1) / 2;
    swap(n, m);
    res = min(res, n / 2 * m + (m + 1) / 2);
    cout << res << endl;
  }

  return 0;
}