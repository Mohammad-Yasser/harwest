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

// Source:
// https://github.com/tfg50/Competitive-Programming/blob/master/Biblioteca/Data%20Structures/SparseTable.cpp
template <class T>
struct Minimizer {
  T operator()(T a, T b) { return std::min(a, b); }
};

template <class T, class Merger = Minimizer<T>>
class SparseTable {
 public:
  void init(const std::vector<T>& a) {
    int e = 0;
    int n = a.size();
    while ((1 << e) / 2 < n) {
      e++;
    }
    table.assign(e, std::vector<T>(n));
    get.assign(n + 1, -1);
    for (int i = 0; i < n; i++) {
      table[0][i] = a[i];
      get[i + 1] = get[(i + 1) / 2] + 1;
    }
    for (int i = 0; i + 1 < e; i++) {
      for (int j = 0; j + (1 << i) < n; j++) {
        table[i + 1][j] = merge(table[i][j], table[i][j + (1 << i)]);
      }
    }
  }

  T qry(int l, int r) {
    int e = get[r - l];
    return merge(table[e][l], table[e][r - (1 << e)]);
  }

  int getPos(int x) {
    while (x >= (int)get.size()) get.push_back(get[(int)get.size() / 2] + 1);
    return get[x];
  }

 private:
  std::vector<std::vector<T>> table;
  std::vector<int> get;
  Merger merge;
};

// Source:
// https://github.com/tfg50/Competitive-Programming/blob/master/Biblioteca/Data%20Structures/FastRMQ.cpp
// O(N) preprocessing, O(1) query Range Minimum Query

template <class T>
class FastRMQ {
 public:
  void init(const std::vector<T>& a) {
    original = a;
    int n = (int)a.size();
    if (n == 0) return;
    e = 1;
    while ((1 << e) < n) e++;
    std::vector<T> groups;
    for (int i = 0; i < n; i++) {
      if (i % e == 0) {
        groups.push_back(a[i]);
      } else if (a[i] < groups.back()) {
        groups.back() = a[i];
      }
    }
    table.init(groups);
    mask.resize(n);
    for (int i = 0, curMask = 0; i < n; i++) {
      curMask = (curMask << 1) & ((1 << e) - 1);
      while (curMask) {
        int j = i - table.getPos(curMask & -curMask);
        if (a[i] < a[j]) {
          curMask ^= curMask & -curMask;
        } else {
          break;
        }
      }
      curMask |= 1;
      mask[i] = curMask;
    }
  }

  T qry(int l, int r) {
    // query in [l, r)
    if (r - l <= e) {
      return i_qry(r - 1, r - l);
    } else {
      T ans = std::min(i_qry(l + e - 1, e), i_qry(r - 1, e));
      if (l / e + 1 < r / e) {
        ans = std::min(ans, table.qry(l / e + 1, r / e));
      }
      return ans;
    }
  }

 private:
  int e;
  SparseTable<T> table;
  std::vector<T> original;
  std::vector<int> mask;

  T i_qry(int r, int size) {
    int curMask = mask[r] & ((1 << size) - 1);
    int pos = r - table.getPos(curMask);
    return original[pos];
  }
};

// Source:
// https://github.com/tfg50/Competitive-Programming/blob/master/Biblioteca/Graph/SimpleEulerTourTree.cpp
template <const bool REPEAT = false>
struct SimpleEulerTourTree {
  void init(const std::vector<std::vector<int>>& edges, int root = 0) {
    a.clear();
    in = out = std::vector<int>(edges.size(), 0);
    dfs(root, root, edges, 0);
  }

  void dfs(int on, int par, const std::vector<std::vector<int>>& edges, int h) {
    in[on] = (int)a.size();
    a.emplace_back(h, on);
    for (auto to : edges[on]) {
      if (to == par) continue;
      dfs(to, on, edges, h + 1);
      if (REPEAT) a.emplace_back(h, on);
    }
    out[on] = (int)a.size();
  }

  std::vector<int> in, out;
  std::vector<std::pair<int, int>> a;
};

// Source:
// https://github.com/tfg50/Competitive-Programming/blob/master/Biblioteca/Graph/FastLCA.cpp
class FastLCA {
 public:
  void init(const std::vector<std::vector<int>>& edges, int root) {
    ett.init(edges, root);
    rmq.init(ett.a);
  }

  int lca(int u, int v) {
    if (ett.in[u] > ett.in[v]) std::swap(u, v);
    return rmq.qry(ett.in[u], ett.out[v]).second;
  }

 private:
  SimpleEulerTourTree<true> ett;
  FastRMQ<std::pair<int, int>> rmq;
};

int parent[N];
bool is_set[N];
bool my_edge[N];

int getRoot(int node) {
  if (!is_set[node]) return node;
  return parent[node] = getRoot(parent[node]);
}

void dfs(int node, int p) {
  parent[node] = p;
  for (int v : my_adj[node]) {
    if (v == p) continue;
    my_edge[v] = true;
    dfs(v, node);
  }
  for (int v : other_adj[node]) {
    if (v == p) continue;
    dfs(v, node);
  }
}

inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  int n = read(), k = read(), m = read();
  // cin >> n >> k >> m;
  dsu.init();
  all_adj.resize(n);
  while (k--) {
    int u = read(), v = read();
    // cin >> u >> v;
    --u, --v;

    my_adj[u].emplace_back(v);
    my_adj[v].emplace_back(u);

    all_adj[u].emplace_back(v);
    all_adj[v].emplace_back(u);

    dsu.join(u, v);
  }

  vector<Constraint> cons;

  while (m--) {
    int u = read(), v = read(), w = read();
    // cin >> u >> v >> w;
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

  dfs(0, 0);
  FastLCA lca_finder;
  lca_finder.init(all_adj, 0);
  Long res = 0;
  for (auto& [u, v, w] : cons) {
    int lca = lca_finder.lca(u, v);
    lca = getRoot(lca), u = getRoot(u), v = getRoot(v);
    for (int x : {u, v}) {
      while (x != lca) {
        is_set[x] = true;
        res += my_edge[x] * w;
        x = getRoot(parent[x]);
      }
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