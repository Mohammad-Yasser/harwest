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

const int N = 3003;

int cnt[N][N];

vector<int> adj[N];

int getCnt(int node, int parent) {
  int& res = cnt[node][parent];
  if (res != -1) return res;
  res = 1;
  for (int v : adj[node]) {
    if (v == parent) continue;
    res += getCnt(v, node);
  }
  return res;
}

Long memo[N][N];
Long solve(int u, int v, int pu, int pv) {
  Long& res = memo[u][v];
  if (res != -1) return res;
  res = 0;
  for (int x : adj[u]) {
    if (x == pu) continue;
    res = max(res, solve(x, v, u, pv) + 1LL * getCnt(x, u) * getCnt(v, pv));
  }
  for (int x : adj[v]) {
    if (x == pv) continue;
    res = max(res, solve(u, x, pu, v) + 1LL * getCnt(x, v) * getCnt(u, pu));
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  memset(cnt, -1, sizeof cnt);
  memset(memo, -1, sizeof memo);
  int n;
  cin >> n;

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  Long res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int v : adj[i]) {
      res = max(res , solve(i , v , v , i) + 1LL * getCnt(i , v) * getCnt(v , i));
    }
  }

  cout << res << endl;

}
