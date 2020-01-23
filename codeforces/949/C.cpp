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

// https://github.com/kmyk/competitive-programming-library
/**
 * @param g is an adjacent list of a digraph
 * @note $O(V + E)$
 * @see https://en.wikipedia.org/wiki/Transpose_graph
 */
vector<vector<int>> make_transpose_graph(const vector<vector<int>>& g) {
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
 * @brief strongly connected components decomposition, Kosaraju's algorithm
 * @return the pair (the number k of components, the function from vertices of g to components)
 * @param g is an adjacent list of a digraph
 * @param g_rev is the transpose graph of g
 * @note $O(V + E)$
 */
pair<int, vector<int>> decompose_to_strongly_connected_components(
  const vector<vector<int>>& g, const vector<vector<int>>& g_rev) {
  int n = g.size();
  vector<int> acc(n);
  {
    vector<bool> used(n);
    function<void(int)> dfs = [&](int i) {
      used[i] = true;
      for (int j : g[i]) if (not used[j]) dfs(j);
      acc.push_back(i);
    };
    for (int i = 0; i < n; ++i)
      if (not used[i]) dfs(i);
    reverse(acc.begin(), acc.end());
  }
  int size = 0;
  vector<int> component_of(n);
  {
    vector<bool> used(n);
    function<void(int)> rdfs = [&](int i) {
      used[i] = true;
      component_of[i] = size;
      for (int j : g_rev[i]) if (not used[j]) rdfs(j);
    };
    for (int i : acc)
      if (not used[i]) {
        rdfs(i);
        ++size;
      }
  }
  return {size, move(component_of)};
}

pair<int, vector<int>> decompose_to_strongly_connected_components(
  const vector<vector<int>>& g) {
  return decompose_to_strongly_connected_components(g, make_transpose_graph(g));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m, h;
  cin >> n >> m >> h;

  vector<vector<int>> graph(n);
  vector<int> hour(n);

  for (int& x : hour) {
    cin >> x;
  }

  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if ((hour[u] + 1) % h == hour[v]) {
      graph[u].emplace_back(v);
    }
    if ((hour[v] + 1) % h == hour[u]) {
      graph[v].emplace_back(u);
    }
  }

  auto scc = decompose_to_strongly_connected_components(graph);
  vector<int> cnt(scc.first);
  vector<bool> is_leaf(scc.first, true);

  for (int i = 0; i < n; ++i) {
    bool leaf = true;
    for (int v : graph[i]) {
      leaf &= (scc.second[v] == scc.second[i]);
    }
    if (!leaf) is_leaf[scc.second[i]] = false;
    ++cnt[scc.second[i]];
  }

  int res = n + 1;
  int best = -1;

  for (int i = 0; i < scc.first; ++i) {
    if (is_leaf[i] && cnt[i] < res) {
      res = cnt[i];
      best = i;
    }
  }

  cout << res << endl;
  for (int i = 0; i < n; ++i) {
    if (scc.second[i] == best) {
      cout << i + 1 << " ";
    }
  }
  cout << endl;
}
