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

const int N = 1e5 + 5;
bool vis[N];

vector<int> adj[N];

int dfs(int node) {
  if (vis[node]) return 0;
  vis[node] = true;
  int res = 1;
  for (int v : adj[node]) {
    res += dfs(v);
  }
  return res;
}

int main() {
  srand(time(0));
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m, k;
  cin >> n >> m >> k;

  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> comp_sizes;
  for (int i = 1; i <= n; ++i) {
    int sz = dfs(i);
    if (sz != 0) {
      comp_sizes.push_back(sz);
    }
  }

  int res = 1 % k;
  for (int i = 0; i + 2 < (int) comp_sizes.size(); ++i) {
    res = 1LL * res * n % k;
  }

  if (comp_sizes.size() != 1) {
    for (int x : comp_sizes) {
      res = 1LL * res * x % k;
    }
  }

  cout << res;

}
