// #ifndef Local
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse4,sse4.2,popcnt,abm,mmx,avx")
// #endif
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
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

// https://github.com/kmyk/competitive-programming-library
/**
 * @param g is an adjacent list of a digraph
 * @note $O(V + E)$
 * @see https://en.wikipedia.org/wiki/Transpose_graph
 */
inline vector<vector<int>> make_transpose_graph(const vector<vector<int>>& g) {
  int n = g.size();
  vector<vector<int>> h(n);
  for (int i = 0; i < n; ++i) {
    for (int j : g[i]) {
      h[j].push_back(i);
    }
  }
  return h;
}

/**
 * @brief strongly connected components decomposition, Kosaraju's algorithm /
 * 強連結成分分解
 * @return the pair (the number k of components, the function from vertices of g
 * to components)
 * @param g is an adjacent list of a digraph
 * @param g_rev is the transpose graph of g
 * @note $O(V + E)$
 */
inline pair<int, vector<int>> decompose_to_strongly_connected_components(
    const vector<vector<int>>& g, const vector<vector<int>>& g_rev) {
  int n = g.size();
  vector<int> acc(n);
  {
    vector<bool> used(n);
    function<void(int)> dfs = [&](int i) {
      used[i] = true;
      for (int j : g[i])
        if (not used[j]) dfs(j);
      acc.push_back(i);
    };
    for (int i = 0; i < n; ++i)
      if (not used[i]) dfs(i);
    reverse(all(acc));
  }
  int size = 0;
  vector<int> component_of(n);
  {
    vector<bool> used(n);
    function<void(int)> rdfs = [&](int i) {
      used[i] = true;
      component_of[i] = size;
      for (int j : g_rev[i])
        if (not used[j]) rdfs(j);
    };
    for (int i : acc)
      if (not used[i]) {
        rdfs(i);
        ++size;
      }
  }
  return {size, move(component_of)};
}

inline vector<int> decompose_to_strongly_connected_components(
    const vector<vector<int>>& g) {
  return decompose_to_strongly_connected_components(g, make_transpose_graph(g))
      .second;
}

const int N = 1e5 + 5;
const int D = 53;

bool open[N][D];
vector<int> scc_id;
vector<vector<int>> graph;

int comp[N][D];  // component of (node, day_of_week) considering only nodes
// in the same SCC.
vector<pair<int, int>> comp_nodes[N * D];
int sz_comp[N * D];  // Number of museums in each component.
int d;
void dfs(int node, int curr_day, vector<bool>& is_vis,
         vector<int>& vis_museums) {
  stack<pair<int, int>> st;
  st.emplace(node, curr_day);
  while (!st.empty()) {
    auto [node, curr_day] = st.top();
    st.pop();
    comp_nodes[comp[node][curr_day]].emplace_back(node, curr_day);
    if (open[node][curr_day] && !is_vis[node]) {
      vis_museums.emplace_back(node);
      is_vis[node] = true;
      ++sz_comp[comp[node][curr_day]];
    }
    int next_day = curr_day + 1;
    if (next_day == d) next_day = 0;
    for (int v : graph[node]) {
      if (scc_id[v] != scc_id[node] || comp[v][next_day] != 0) continue;
      comp[v][next_day] = comp[node][curr_day];
      st.emplace(v, next_day);
    }
  }
}

int memo[N * D];

int solve(int node, int curr_day) {
  if (curr_day == d) curr_day = 0;
  int& res = memo[comp[node][curr_day]];
  if (res != -1) return res;
  res = 0;
  for (auto [u, day] : comp_nodes[comp[node][curr_day]]) {
    for (int v : graph[u]) {
      if (scc_id[u] != scc_id[v]) {
        assert(scc_id[v] > scc_id[u]);
        res = max(res, solve(v, day + 1));
      }
    }
  }
  res += sz_comp[comp[node][curr_day]];
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m >> d;
  graph.resize(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    graph[u].emplace_back(v);
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < d; ++j) {
      char c;
      cin >> c;
      open[i][j] = (c == '1');
    }
  }

  scc_id = decompose_to_strongly_connected_components(graph);

  vector<bool> is_vis(n + 1);
  vector<int> vis_museums;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < d; ++j) {
      if (comp[i][j] == 0) {
        comp[i][j] = (i - 1) * d + j + 1;
        dfs(i, j, is_vis, vis_museums);
        for (int x : vis_museums) {
          is_vis[x] = false;
        }
        vis_museums.clear();
      }
    }
  }

  memset(memo, -1, sizeof memo);
  cout << solve(1, 0) << endl;
  return 0;
}