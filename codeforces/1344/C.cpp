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

template <typename T>
void minimize(T& x, const T& y) {
  x = min(x, y);
}

template <typename T>
void maximize(T& x, const T& y) {
  x = max(x, y);
}

typedef long long Long;

const int N = 2e5 + 5;

vector<int> out[N], in[N];

bool dfs(int node) {
  static bool vis[N];
  static bool grey[N];
  if (grey[node]) return true;
  if (vis[node]) return false;
  grey[node] = vis[node] = true;
  for (int v : out[node]) {
    if (dfs(v)) return true;
  }
  grey[node] = false;
  return false;
}

string res;
void mark(int node, bool _in) {
  static bool vis[N][2];
  if (vis[node][_in]) return;
  vis[node][_in] = true;
  res[node - 1] = 'E';
  if (_in) {
    for (int v : in[node]) {
      mark(v, true);
    }
  } else {
    for (int v : out[node]) {
      mark(v, false);
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
    if (u == v) {
      cout << -1 << endl;
      return 0;
    }
    out[u].emplace_back(v);
    in[v].emplace_back(u);
  }

  for (int i = 1; i <= n; ++i) {
    if (dfs(i)) {
      cout << -1 << endl;
      return 0;
    }
  }

  res.resize(n, 'A');
  for (int i = 1; i <= n; ++i) {
    char tmp = res[i - 1];
    mark(i, true);
    mark(i, false);
    res[i - 1] = tmp;
  }
  int cnt = count(res.begin(), res.end(), 'A');
  cout << cnt << endl;
  cout << res << endl;

  return 0;
}
