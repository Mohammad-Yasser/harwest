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

const int N = 101;
set<int> st[N][N];
int grid[N][N];

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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x2 -= x1 - 1, y2 -= y1 - 1;
    cout << 1 + 1LL * (x2 - 1) * (y2 - 1) << endl;
  }
  return 0;

  // Stupid pattern -_-

  int n = 10;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int diag = i + j;
      int st = diag * (diag + 1) / 2;
      grid[i][j] = st + i + 1;
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }

  for (int i = 3; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      if (j > 0)
        for (int x : st[i][j - 1]) {
          st[i][j].emplace(x + grid[i][j]);
        }
      if (i > 0)
        for (int x : st[i - 1][j]) {
          st[i][j].emplace(x + grid[i][j]);
        }
      if (st[i][j].empty()) {
        st[i][j].emplace(grid[i][j]);
      }
      cout << st[i][j].size() << " ";
    }
    cout << endl;
  }

  return 0;
}