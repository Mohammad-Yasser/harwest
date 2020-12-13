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

// Either globally or in a single class:
// static char buf[200 << 20];
// void* operator new(size_t s) {
//   static size_t i = sizeof buf;
//   assert(s < i);
//   return (void*)&buf[i -= s];
// }
// void operator delete(void*) {}

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

using Constraint = pair<int, int>;

vector<Constraint> cons[N];

vector<int> my_adj[N];
vector<int> other_adj[N];
vector<vi> all_adj;

template <typename T, typename U>
struct SegmentTree {
  int S, H;

  T zero;
  vector<T> value;

  U noop;
  vector<bool> dirty;
  vector<U> prop;

  void init(int _S = N, T _zero = T(), U _noop = U()) {
    zero = _zero, noop = _noop;
    for (S = 1, H = 1; S < _S;) S *= 2, H++;
    value.clear(), dirty.clear(), prop.clear();
    value.resize(2 * S, zero);
    dirty.resize(2 * S, false);
    prop.resize(2 * S, noop);
  }

  SegmentTree<T, U>(int _S = N, T _zero = T(), U _noop = U()) {
    init(_S, _zero, _noop);
  }

  void set_leaves(vector<T>& leaves) {
    copy(leaves.begin(), leaves.end(), value.begin() + S);

    for (int i = S - 1; i > 0; i--) value[i] = value[2 * i] + value[2 * i + 1];
  }

  void apply(int i, const U& update) {
    value[i] = update(value[i]);
    if (i < S) {
      prop[i] = prop[i] + update;
      dirty[i] = true;
    }
  }

  void rebuild(int i) {
    for (int l = i / 2; l; l /= 2) {
      T combined = value[2 * l] + value[2 * l + 1];
      value[l] = prop[l](combined);
    }
  }

  void propagate(int i) {
    for (int h = H; h > 0; h--) {
      int l = i >> h;

      if (dirty[l]) {
        apply(2 * l, prop[l]);
        apply(2 * l + 1, prop[l]);

        prop[l] = noop;
        dirty[l] = false;
      }
    }
  }

  void upd(int i, int j, const U& update) {
    if (i > j) return;
    i += S, j += S;
    propagate(i), propagate(j);

    for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
      if ((l & 1) == 1) apply(l++, update);
      if ((r & 1) == 0) apply(r--, update);
    }

    rebuild(i), rebuild(j);
  }

  T query(int i, int j) {
    if (i > j) return zero;
    i += S, j += S;
    propagate(i), propagate(j);

    T res_left = zero, res_right = zero;
    for (; i <= j; i /= 2, j /= 2) {
      if ((i & 1) == 1) res_left = res_left + value[i++];
      if ((j & 1) == 0) res_right = value[j--] + res_right;
    }
    return res_left + res_right;
  }
};

const int OO = 2e9;

struct Node {
  int val = OO;
  Node operator+(const Node& right) const {
    Node res = *this;
    res.val = min(res.val, right.val);
    return res;
  }
};

// The default value must not change an update when merged.
// I.e. any_update + Update() must be = any_update.
struct Update {
  int val = OO;
  Update(int val = OO) : val(val) {}
  Update operator+(const Update& right) const {
    Update res = *this;
    res.val = min(res.val, right.val);
    return res;
  }
  Node operator()(const Node& node) const {
    Node res = node;
    res.val = min(res.val, val);
    return res;
  }
};

template <bool VALS_EDGES>
struct HLD {
  int N, tim = 0;
  vector<vi> adj;
  vi par, siz, depth, rt, pos;
  SegmentTree<Node, Update> tree;
  HLD(vector<vi> adj_)
      : N(sz(adj_)),
        adj(adj_),
        par(N, -1),
        siz(N, 1),
        depth(N),
        rt(N),
        pos(N),
        tree(N) {
    dfsSz(0);
    dfsHld(0);
  }
  void dfsSz(int v) {
    if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
    for (int& u : adj[v]) {
      par[u] = v, depth[u] = depth[v] + 1;
      dfsSz(u);
      siz[v] += siz[u];
      if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
    }
  }
  void dfsHld(int v) {
    pos[v] = tim++;
    for (int u : adj[v]) {
      rt[u] = (u == adj[v][0] ? rt[v] : u);
      dfsHld(u);
    }
  }
  template <class B>
  void process(int u, int v, B op) {
    for (; rt[u] != rt[v]; v = par[rt[v]]) {
      if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
      op(pos[rt[v]], pos[v] + 1);
    }
    if (depth[u] > depth[v]) swap(u, v);
    op(pos[u] + VALS_EDGES, pos[v] + 1);
  }
  void modifyPath(int u, int v, int val) {
    Update update(val);
    process(u, v, [&](int l, int r) {
      if (l != r) tree.upd(l, r - 1, update);
    });
  }
  Node queryPath(int u, int v) {  // Modify depending on problem
    Node res;
    process(u, v, [&](int l, int r) {
      if (l != r) res = res + tree.query(l, r - 1);
    });
    return res;
  }
  Node querySubtree(int v) {  // modifySubtree is similar
    return tree.query(pos[v] + VALS_EDGES, pos[v] + siz[v] - 1);
  }
};

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
  all_adj.resize(n);
  dsu.init();
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

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    if (dsu.getRoot(u) == dsu.getRoot(v)) {
      cons[u].emplace_back(v, w);
      cons[v].emplace_back(u, w);
    } else {
      dsu.join(u, v);
      other_adj[u].emplace_back(v);
      other_adj[v].emplace_back(u);
      all_adj[u].emplace_back(v);
      all_adj[v].emplace_back(u);
    }
  }

  HLD<true> hld(all_adj);

  for (int i = 0; i < n; ++i) {
    for (auto [v, w] : cons[i]) {
      if (i > v) continue;
      hld.modifyPath(i, v, w);
    }
  }

  Long res = 0;
  for (int i = 0; i < n; ++i) {
    for (int v : my_adj[i]) {
      if (i > v) continue;
      auto tmp = hld.queryPath(i, v);
      if (tmp.val == OO) {
        cout << -1 << endl;
        return 0;
      }
      res += tmp.val;
    }
  }

  cout << res << endl;

  return 0;
}