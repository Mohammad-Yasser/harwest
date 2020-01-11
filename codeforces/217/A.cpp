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

const int N = 1003;

struct DSU {
  int parent[N];

  DSU() {
    for (int i = 0; i < N; ++i) {
      parent[i] = i;
    }
  }

  int getRoot(int node) {
    if (node == parent[node]) return node;
    return parent[node] = getRoot(parent[node]);
  }

  void join(int x, int y) {
    x = getRoot(x);
    y = getRoot(y);
    parent[x] = y;
  }
} dsu;

int row_ind[N];
int col_ind[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    if (row_ind[x] != 0) {
      dsu.join(i, row_ind[x]);
    }
    if (col_ind[y] != 0) {
      dsu.join(i, col_ind[y]);
    }
    row_ind[x] = col_ind[y] = i;
  }

  int res = 0;
  for (int i = 1; i <= n; ++i) {
    res += (dsu.getRoot(i) == i);
  }

  cout << res - 1 << endl;
}
