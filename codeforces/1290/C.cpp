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

const int N = 6e5 + 50;

const int ON = N / 2 - 3;
const int OO = 1e6;

struct DSU {
  int parent[N];
  int cost[N];
  int total_cost = 0;

  void init() {
    for (int i = 0; i < N; ++i) {
      parent[i] = i;
      cost[i] = (i % 2 == 0);
    }
    cost[2 * ON] = 0;
    cost[2 * ON + 1] = OO;
    total_cost = 0;
  }

  int getRoot(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
  }

  void join(int x, int y, bool same) {
    int pos_x = 2 * x, neg_x = 2 * x + 1;
    int pos_y = 2 * y, neg_y = 2 * y + 1;

    pos_x = getRoot(pos_x), neg_x = getRoot(neg_x);
    pos_y = getRoot(pos_y), neg_y = getRoot(neg_y);

    if (same) {
      if (pos_x == pos_y) return;
      total_cost -= min(cost[pos_y], cost[neg_y]);
      total_cost -= min(cost[pos_x], cost[neg_x]);

      cost[pos_y] += cost[pos_x];
      cost[neg_y] += cost[neg_x];

      parent[pos_x] = pos_y;
      parent[neg_x] = neg_y;
    } else {
      if (pos_x == neg_y) return;
      total_cost -= min(cost[pos_y], cost[neg_y]);
      total_cost -= min(cost[pos_x], cost[neg_x]);

      cost[pos_y] += cost[neg_x];
      cost[neg_y] += cost[pos_x];

      parent[pos_x] = neg_y;
      parent[neg_x] = pos_y;
    }
    total_cost += min(cost[pos_y], cost[neg_y]);
  }

} dsu;

vector<int> opt[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  dsu.init();

  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  for (int i = 1; i <= k; ++i) {
    int c;
    cin >> c;
    while (c--) {
      int x;
      cin >> x;
      --x;
      opt[x].emplace_back(i);
    }
  }


  for (int i = 0; i < n; ++i) {
    if (opt[i].size() == 1) {
      dsu.join(opt[i].back(), ON, s[i] == '0');
    }
    if (opt[i].size() == 2) {
      dsu.join(opt[i][0], opt[i][1], s[i] == '1');
    }
    cout << dsu.total_cost << endl;
  }
}