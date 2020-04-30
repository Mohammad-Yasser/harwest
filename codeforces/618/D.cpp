#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)

typedef long long Long;
typedef vector<int> vi;

const int N = 2e5 + 5;

vector<int> adj[N];
int out[N];

int dfs(int node, int parent) {
  int cnt = 0;
  int res = 0;
  for (int v : adj[node]) {
    if (v == parent) continue;
    res += dfs(v, node);
    cnt += out[v];
  }
  if (cnt > 1) {
    --res;
  } else {
    out[node] = 1;
    res += !cnt;
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

  int n, x, y;
  cin >> n >> x >> y;
  int leaves = 0;
  int mx = 0;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v), adj[v].emplace_back(u);
    mx = max(mx, (int)adj[u].size());
    mx = max(mx, (int)adj[v].size());
  }

  if (y <= x) {
    if (mx == n - 1) {
      cout << 1LL * y * (n - 2) + x << endl;
    } else {
      cout << 1LL * y * (n - 1) << endl;
    }
    return 0;
  }

  int l = dfs(1, -1) - 1;
  Long res = 1LL * y * l;
  res += 1LL * x * (n - 1 - l);

  cout << res << endl;

  return 0;
}
