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

const int N = 2e5 + 5;

vector<int> adj[N];
int mx[N];
int comp_id[N];

void dfs(int node, int id) {
  for (int v : adj[node]) {
    if (comp_id[v] == -1) {
      comp_id[v] = id;
      mx[id] = max(mx[id], v);
      dfs(v, id);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;

  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<pair<int, int>> v;
  memset(comp_id, -1, sizeof comp_id);
  for (int i = 1; i <= n; ++i) {
    if (comp_id[i] == -1) {
      comp_id[i] = mx[i] = i;
      dfs(i, i);
      v.emplace_back(i, mx[i]);
    }
  }
  sort(v.begin(), v.end());
  int res = 0;
  int mx = 0;
  for (auto& p : v) {
    if (mx > p.first) {
      ++res;
    }
    mx = max(mx, p.second);
  }

  cout << res << endl;

}
