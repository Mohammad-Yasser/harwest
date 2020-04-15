#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define all(v) begin(v), end(v)

typedef long long Long;
typedef vector<int> vi;

const int N = 2e5 + 5;

int score[N];
int sz[N];
vector<int> adj[N];

void dfs(int node, int parent, int depth) {
  sz[node] = 1;
  score[node] = depth;
  for (auto& v : adj[node]) {
    if (v == parent) continue;
    dfs(v, node, depth + 1);
    sz[node] += sz[v];
  }
  score[node] -= sz[node] - 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  dfs(1, -1, 0);
  sort(score + 1, score + n + 1, greater<int>());
  Long res = 0;
  for (int i = 1; i <= k; ++i) {
    res += score[i];
  }
  cout << res << endl;
  return 0;
}
