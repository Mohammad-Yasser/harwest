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

const int N = 1003;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;
  string row;
  while (t--) {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    y = min(y, 2 * x);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      cin >> row;
      for (int j = 0; j < m; ++j) {
        if (row[j] == '.') {
          if (j + 1 < m && row[j + 1] == '.') {
            res += y;
            ++j;
          } else {
            res += x;
          }
        }
      }
    }
    cout << res << endl;
  }

  return 0;
}