#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int MOD = 998244353;
const int N = 4e5 + 5;

Long pw2[N];

void build() {
  pw2[0] = 1;
  for (int i = 1; i < N; ++i) {
    pw2[i] = 2LL * pw2[i - 1] % MOD;
  }
}

vector<int> adj[N];

int vis_id;
int vis[N];
bool par[N];

pair<int, int> dfs(int node, bool parity) {
  if (vis[node] == vis_id) {
    if (par[node] == parity) {
      return {0,0};
    } else {
      return {-1,-1};
    }
  }

  vis[node] = vis_id;
  par[node] = parity;

  pair<int, int> res = { !parity, parity };
  for (int v : adj[node]) {
    auto tmp = dfs(v, !parity);
    if (tmp.first == -1) return tmp;
    res.first += tmp.first;
    res.second += tmp.second;
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

  build();

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      adj[i].clear();
    }
    ++vis_id;
    while (m--) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    Long ways = 1;
    for (int i = 1; i <= n; ++i) {
      if (vis[i] == vis_id) continue;
      auto res = dfs(i, false);
      if (res.first == -1) {
        ways = 0;
        break;
      }
      Long tmp = (pw2[res.first] + pw2[res.second]) % MOD;
      ways = 1LL * tmp * ways % MOD;
    }
    cout << ways << endl;
  }

}
