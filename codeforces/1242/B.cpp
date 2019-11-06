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

const int N = 1e5 + 5;
struct DSU {
  int parent[N];
  void init(int n) {
    for (int i = 0; i <= n; ++i) {
      parent[i] = i;
    }
  }
  int getRoot(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
  }

  void join(int x, int y) {
    if (rand() & 1) swap(x, y);
    x = getRoot(x), y = getRoot(y);
    parent[x] = y;
  }
} dsu;

vector<int> adj[N];
bool vis[N];

int Random(int n) {
  unsigned long long ret = rand();
  ret *= 32768;
  ret += rand();
  return ret % n;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  srand(time(0));

  int n, m;
  cin >> n >> m;

  dsu.init(n);

  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; ++i) {
    for (int x : adj[i]) {
      vis[x] = true;
    }
    if (adj[i].size() >= n / 170) {
      for (int j = 1; j <= n; ++j) {
        if (!vis[j]) {
          dsu.join(i, j);
        }
      }
    } else {
      for (int j = 1; j <= 170; ++j) {
        int x = Random(n) + 1;
        if (!vis[x]) {
          dsu.join(i, x);
        }
      }
    }
    for (int x : adj[i]) {
      vis[x] = false;
    }
  }

  int res = 0;
  for (int i = 1; i <= n; ++i) {
    res += (i == dsu.getRoot(i));
  }
  cout << res - 1 << endl;

}
