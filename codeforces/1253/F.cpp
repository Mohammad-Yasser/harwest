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

const int N = 3e5 + 5;
const Long OO = 1e17;
Long dist[N];
int nearest_central[N];

vector<pair<int, int>> adj[N];
int k;

void dijkstra() {
  fill(dist, dist + N, OO);
  set<tuple<Long, int, int>> pq;
  for (int i = 1; i <= k; ++i) {
    pq.emplace(0, i, i);
    dist[i] = 0;
  }

  while (!pq.empty()) {
    auto curr = *pq.begin();
    pq.erase(pq.begin());
    Long d;
    int central, node;
    tie(d, central, node) = curr;
    if (d > dist[node]) continue;
    nearest_central[node] = central;
    for (auto& p : adj[node]) {
      if (d + p.second < dist[p.first]) {
        dist[p.first] = d + p.second;
        pq.emplace(dist[p.first], central, p.first);
      }
    }
  }
}

int n, m, q;

vector<tuple<Long, int, int>> getEdges() {
  vector<tuple<Long, int, int>> edges;
  for (int u = 1; u <= n; ++u) {
    for (auto& v : adj[u]) {
      edges.emplace_back(v.second + dist[u] + dist[v.first], nearest_central[u],
        nearest_central[v.first]);
    }
  }
  return edges;
}

Long res[N];

vector<pair<int, int>> queries[N];

struct DSU {
  int parent[N];

  void init() {
    for (int i = 0; i < N; ++i) {
      parent[i] = i;
    }
  }

  int getRoot(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
  }

  void join(int x, int y, Long w) {
    x = getRoot(x);
    y = getRoot(y);
    if (x == y) return;
    if (queries[x].size() > queries[y].size()) swap(x, y);
    for (auto& q : queries[x]) {
      if (getRoot(q.first) == y) {
        res[q.second] = w;
      } else {
        queries[y].emplace_back(q);
      }
    }
    parent[x] = y;
  }
} dsu;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n >> m >> k >> q;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  dijkstra();

  for (int i = 0; i < q; ++i) {
    int u, v;
    cin >> u >> v;
    queries[u].emplace_back(v, i);
    queries[v].emplace_back(u, i);
  }

  auto edges = getEdges();
  sort(edges.begin(), edges.end());
  dsu.init();
  for (auto& edge : edges) {
    dsu.join(get<1>(edge), get<2>(edge), get<0>(edge));
  }

  for (int i = 0; i < q; ++i) {
    cout << res[i] << endl;
  }

}
