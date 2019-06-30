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

vector<int> adj[N];

Long size_down[N];
Long res_down[N];

Long best = 0;

Long res_up[N];
int n;

void dfsDown(int node, int parent = -1) {
  size_down[node] = 1;
  res_down[node] = 0;

  for (int v : adj[node]) {
    if (v != parent) {
      dfsDown(v, node);
      size_down[node] += size_down[v];
      res_down[node] += res_down[v];
    }
  }

  res_down[node] += size_down[node];
}

void dfsUp(int node, int parent = -1) {
  for (int v : adj[node]) {
    if (v != parent) {
      res_up[v] = res_up[node];
      res_up[v] += res_down[node] - res_down[v] - size_down[node];
      res_up[v] += n - size_down[v] + 1;
      res_up[v] += size_down[node] - 1 - size_down[v];
      dfsUp(v, node);
    }
  }

  best = max(best, res_down[node] + res_up[node] - 1);
}

void bf() {
  for (int i = 1; i <= n; ++i) {
    dfsDown(i, -1);
    cout << i << " " << res_down[i] << endl;
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

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfsDown(1);
  res_up[1] = 1;
  dfsUp(1);

  cout << best << endl;

}
