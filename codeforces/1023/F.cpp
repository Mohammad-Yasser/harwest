// #ifndef Local
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("popcnt,abm,mmx,avx2")
// #endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define rep(i, l, r) for (int i = l; i < r; ++i)
typedef long long Long;
typedef double Double;

template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

const int N = 5e5 + 5;

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
  void join(int x, int y) {
    x = getRoot(x);
    y = getRoot(y);
    parent[x] = y;
  }
} dsu;

using vi = vector<int>;

using Constraint = tuple<int, int, int>;

vector<int> adj[N];
int my_adj_sz[N];

int parent[N];
int depth[N];
vector<bool> is_set, my_edge;

int getRoot(int node) {
  if (!is_set[node]) return node;
  return parent[node] = getRoot(parent[node]);
}

void dfs(int node) {
  for (int i = 0; i < sz(adj[node]); ++i) {
    int v = adj[node][i];
    if (v == parent[node]) continue;
    my_edge[v] = (i < my_adj_sz[node]);
    parent[v] = node;
    depth[v] = depth[node] + 1;
    dfs(v);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif
  int n, k, m;
  cin >> n >> k >> m;
  dsu.init();
  is_set.resize(n);
  my_edge.resize(n);

  while (k--) {
    int u, v;
    cin >> u >> v;
    --u, --v;

    adj[u].emplace_back(v);
    adj[v].emplace_back(u);

    dsu.join(u, v);
  }

  for (int i = 0; i < n; ++i) {
    my_adj_sz[i] = sz(adj[i]);
  }

  vector<Constraint> cons;

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    int ru = dsu.getRoot(u);
    int rv = dsu.getRoot(v);
    if (ru == rv) {
      cons.emplace_back(u, v, w);
    } else {
      dsu.parent[ru] = rv;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
  }

  dfs(0);

  Long res = 0;
  for (auto& [u, v, w] : cons) {
    u = getRoot(u), v = getRoot(v);
    while (u != v) {
      if (depth[u] < depth[v]) swap(u, v);
      is_set[u] = true;
      res += my_edge[u] * w;
      u = getRoot(parent[u]);
    }
  }

  for (int i = 1; i < n; ++i) {
    if (my_edge[i] && !is_set[i]) {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << res << endl;

  return 0;
}