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

const int N = 1e6 + 3;

int left_border = 0, right_border = 1;
int up_border = 2, down_border = 3;

struct DSU {
  int parent[4 * N];

  void init() {
    for (int i = 1; i < 4 * N; ++i) {
      parent[i] = i;
    }
  }

  int getRoot(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
  }

  void join(int x, int y) {
    x = getRoot(x), y = getRoot(y);
    parent[x] = y;
  }

  int getNode(int ind, int border) {
    return border * N + ind;
  }

} dsu;

int n, m;

void connect_corners() {
  for (int q = 0; q < 2; ++q) {
    dsu.join(dsu.getNode(1, left_border), dsu.getNode(1, up_border));
    dsu.join(dsu.getNode(n, left_border), dsu.getNode(1, down_border));

    dsu.join(dsu.getNode(1, right_border), dsu.getNode(m, up_border));
    dsu.join(dsu.getNode(n, right_border), dsu.getNode(m, down_border));

    swap(n, m);
    swap(left_border, up_border);
    swap(right_border, down_border);
  }
}

int solve() {
  dsu.init();
  connect_corners();

  for (int q = 0; q < 2; ++q) {
    for (int i = 1; i <= n; ++i) {
      int x = i;
      // Go up
      if (x <= m) {
        // Hit the upper border
        dsu.join(dsu.getNode(i, left_border), dsu.getNode(x, up_border));
        dsu.join(dsu.getNode(i, right_border),
          dsu.getNode(m - x + 1, up_border));
      } else {
        // Hit the opposite border
        dsu.join(dsu.getNode(i, left_border),
          dsu.getNode(x - m + 1, right_border));
        dsu.join(dsu.getNode(i, right_border),
          dsu.getNode(x - m + 1, left_border));
      }

      x = n - i + 1;
      // Go down
      if (x <= m) {
        // Hit the lower border
        dsu.join(dsu.getNode(i, left_border), dsu.getNode(x, down_border));
        dsu.join(dsu.getNode(i, right_border),
          dsu.getNode(m - x + 1, down_border));
      } else {
        // Hit the opposite border
        dsu.join(dsu.getNode(i, left_border),
          dsu.getNode(i + m - 1, right_border));
        dsu.join(dsu.getNode(i, right_border),
          dsu.getNode(i + m - 1, left_border));
      }
    }
    swap(n, m);
    swap(left_border, up_border);
    swap(right_border, down_border);
  }

  int res = 0;

  for (int q = 0; q < 2; ++q) {
    for (int i = 1; i <= n; ++i) {
      res += dsu.parent[dsu.getNode(i, left_border)]
        == dsu.getNode(i, left_border);
      res += dsu.parent[dsu.getNode(i, right_border)]
        == dsu.getNode(i, right_border);
    }
    swap(n, m);
    swap(left_border, up_border);
    swap(right_border, down_border);
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

  cin >> n >> m;
  cout << solve() << endl;

  return 0;
}
