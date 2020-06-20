#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
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

pair<int, int> ask(const vector<int>& nodes) {
  cout << "? " << sz(nodes) << " " << nodes << endl;
  pair<int, int> res;
  cin >> res.first >> res.second;
  return res;
}

void guess(int a, int b) {
  cout << "! " << a << " " << b << endl;
  string correct;
  cin >> correct;
}

const int N = 1003;

vector<int> adj[N];
vector<int> nodes_by_depth[N];
int n;
int dist;
int memo[N];
int parent[N];
int depth[N];

void init() {
  for (int i = 0; i < N; ++i) {
    adj[i].clear();
    nodes_by_depth[i].clear();
    memo[i] = 0;
  }
}

void dfs(int node, int parent, int d) {
  ::parent[node] = parent;
  depth[node] = d;
  nodes_by_depth[d].emplace_back(node);
  for (int v : adj[node]) {
    if (v == parent) continue;
    dfs(v, node, d + 1);
  }
}

int getNode(int depth) {
  int& res = memo[depth];
  if (res != 0) return res;
  if (nodes_by_depth[depth].empty()) return res = -1;
  int node, d;
  tie(node, d) = ask(nodes_by_depth[depth]);
  if (d != dist) return res = -1;
  return res = node;
}

int bs() {
  int low = 0, high = N - 1, ans;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (getNode(mid) != -1) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return getNode(ans);
}

void solve() {
  vector<int> all_nodes;
  for (int i = 1; i <= n; ++i) {
    all_nodes.emplace_back(i);
  }
  int root;
  tie(root, dist) = ask(all_nodes);
  dfs(root, -1, 0);

  int a = bs();
  int depth_a = depth[a];
  int depth_b = dist - depth_a;

  if (depth_b == 0) {
    guess(root, a);
    return;
  }

  // Remove a's ancestor at depth depth_b
  int curr = a;
  while (depth[curr] > depth_b) {
    curr = parent[curr];
  }
  nodes_by_depth[depth_b].erase(find(all(nodes_by_depth[depth_b]), curr));

  int b = ask(nodes_by_depth[depth_b]).first;
  guess(a, b);
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    init();
    cin >> n;
    for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
    solve();
  }
  return 0;
}