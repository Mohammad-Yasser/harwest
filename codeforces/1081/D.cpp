//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse4.1,sse4.2,ssse3,sse3,sse2,sse,avx")
//#pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = 1e5 + 5;

vector<pair<int, int>> adj[N];

int vis[N];
int vis_id;
int comp[N];

int max_w, comp_id;

void dfs(int node) {
  if (vis[node] == vis_id) return;
  vis[node] = vis_id;
  comp[node] = comp_id;
  for (auto v : adj[node]) {
    if (v.second > max_w) continue;
    dfs(v.first);
  }
}

vector<int> special;

int n;
bool validate() {
  ++vis_id;
  comp_id = 0;
  for (int i = 1; i <= n; ++i) {
    if (vis[i] == vis_id) continue;
    ++comp_id;
    dfs(i);
  }
  comp_id = comp[special[0]];
  for (int x : special) {
    if (comp[x] != comp_id) return false;
  }
  return true;
}

int solve() {
  int low = 0, high = 1e9 + 5, mid, ans = 0;
  while (low <= high) {
    mid = (low + high) / 2;
    max_w = mid;
    if (validate()) {
      high = mid - 1;
    } else {
      ans = mid;
      low = mid + 1;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int m, k;
  cin >> n >> m >> k;

  special.resize(k);
  for (int& x : special) {
    cin >> x;
  }

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  int res = solve();

  while (k--) {
    cout << res + 1 << " ";
  }
}
