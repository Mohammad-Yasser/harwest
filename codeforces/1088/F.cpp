#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

constexpr int N = 5e5 + 5;
const int Lg = log2(N) + 3;

vector<int> adj[N];
Long w[N];

int root = 1;
int n;

struct LCAFinder {
  int lvl[N], anc[N][Lg];

  void dfs(int node, int parent) {
    for (int child : adj[node]) {
      if (child == parent) continue;
      anc[child][0] = node;
      lvl[child] = lvl[node] + 1;
      dfs(child, node);
    }
  }

  void buildLCA() {
    memset(anc, 0, sizeof anc);
    lvl[root] = 0;
    dfs(root, -1);
    for (int j = 1; j < Lg; ++j) {
      for (int i = 1; i <= n; ++i) {
        anc[i][j] = anc[anc[i][j - 1]][j - 1];
      }
    }
  }

  int LCA(int i, int j) { // returns node ID (LCA for i, j)
    int st = Lg;
    if (lvl[i] > lvl[j]) swap(i, j);
    int cur = lvl[j];
    for (; st >= 0; st--)
      if (cur - (1 << st) >= lvl[i]) cur -= (1 << st), j = anc[j][st];
    if (i == j) return i;
    cur = lvl[i];
    for (st = Lg; st >= 0; st--)
      if (anc[i][st] != anc[j][st]) cur -= (1 << st), i = anc[i][st], j =
        anc[j][st];
    return anc[i][0];
  }
} lca_finder;

Long solve() {
  lca_finder.buildLCA();
  Long res = 0;
  for (int i = 1; i <= n; ++i) {
    if (i == root) continue;
    Long mn = LLONG_MAX;
    for (int j = 0; j < Lg; ++j) {
      int par = lca_finder.anc[i][j];
      Long cost;
      if (par == 0) {
        par = root;
      }
      cost = (j + 1) * w[par];
      mn = min(mn, cost);
    }
    res += mn + w[i];
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

  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
    if (w[i] < w[root]) {
      root = i;
    }
  }

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  cout << solve();

}
