#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("popcnt,abm,mmx,avx2")
#endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define rep(i, l, r) for (int i = l; i < r; ++i)
typedef long long Long;
typedef double Double;

// Either globally or in a single class:
static char buf[200 << 20];
void* operator new(size_t s) {
  static size_t i = sizeof buf;
  assert(s < i);
  return (void*)&buf[i -= s];
}
void operator delete(void*) {}

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

vector<int> my_adj[N];
vector<int> other_adj[N];
vector<vi> all_adj;

int parent[N];
int depth[N];
bool is_set[N];
bool my_edge[N];

int getRoot(int node) {
  if (!is_set[node]) return node;
  return parent[node] = getRoot(parent[node]);
}

void dfs(int node) {
  for (int i = 0; i < 2; ++i) {
    my_adj[node].swap(other_adj[node]);
    for (int v : my_adj[node]) {
      if (v == parent[node]) continue;
      my_edge[v] = i;
      parent[v] = node;
      depth[v] = depth[node] + 1;
      dfs(v);
    }
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
  all_adj.resize(n);
  while (k--) {
    int u, v;
    cin >> u >> v;
    --u, --v;

    my_adj[u].emplace_back(v);
    my_adj[v].emplace_back(u);

    all_adj[u].emplace_back(v);
    all_adj[v].emplace_back(u);

    dsu.join(u, v);
  }

  vector<Constraint> cons;

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    if (dsu.getRoot(u) == dsu.getRoot(v)) {
      cons.emplace_back(u, v, w);
    } else {
      dsu.join(u, v);
      other_adj[u].emplace_back(v);
      other_adj[v].emplace_back(u);

      all_adj[u].emplace_back(v);
      all_adj[v].emplace_back(u);
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