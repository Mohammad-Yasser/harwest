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

const int N = 2e5 + 5;

vector<pair<int, int>> adj[N];

int n;
bool check() {
  for (int i = 1; i <= n; ++i) {
    if (adj[i].size() == 2) return false;
  }
  return true;
}

int getLeaf(int node, int parent) {
  if (adj[node].size() == 1) return node;
  for (auto v : adj[node]) {
    if (v.first != parent) return getLeaf(v.first, node);
  }
  assert(node == -1);
  return -1;
}

bool add(int a, int b, int x, int parent = -1) {
  if (a == b) return true;
  for (auto& v : adj[a]) {
    if (v.first == parent) continue;
    if (add(v.first, b, x, a)) {
      v.second -= x;
      return true;
    }
  }
  return false;
}

vector<tuple<int, int, int>> res;

void solve(int node, int parent) {
  if (adj[node].size() == 1) return;

  int a_leaf = getLeaf(adj[node][0].first, node);
  int b_leaf = getLeaf(adj[node][1].first, node);

  for (int i = 2; i < adj[node].size(); ++i) {
    int a_val = adj[node][0].second;
    int b_val = adj[node][1].second;

    int c_val = adj[node][i].second;
    int c_leaf = getLeaf(adj[node][i].first, node);

    int x = (a_val + b_val - c_val) / 2;
    int y = (a_val + c_val - b_val) / 2;
    int z = (b_val + c_val - a_val) / 2;

    res.emplace_back(a_leaf, b_leaf, x);
    res.emplace_back(a_leaf, c_leaf, y);
    res.emplace_back(b_leaf, c_leaf, z);

    add(a_leaf, b_leaf, x);
    add(a_leaf, c_leaf, y);
    add(b_leaf, c_leaf, z);

    add(b_leaf, a_leaf, x);
    add(c_leaf, a_leaf, y);
    add(c_leaf, b_leaf, z);
  }

  for (auto& v : adj[node]) {
    if (v.first == parent) continue;
    solve(v.first, node);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cerr.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n;

  if (n == 2) {
    int w;
    cin >> w >> w >> w;
    cout << "YES" << endl;
    cout << 1 << endl;
    cout << 1 << " " << 2 << " " << w << endl;
    return 0;
  }

  for (int i = 1; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  if (!check()) {
    cout << "NO";
    return 0;
  }

  for (int i = 1; i <= n; ++i) {
    if (adj[i].size() != 1) {
      solve(i, -1);
      break;
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (auto& v : adj[i]) {
      if (v.second != 0) {
        cout << "NO";
        return 0;
      }
    }
  }

  cout << "YES" << endl;

  cout << res.size() << endl;

  for (auto x : res) {
    cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;
  }

}
