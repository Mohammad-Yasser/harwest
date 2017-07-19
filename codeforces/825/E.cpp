#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef long double Double;

const int N = 1e5 + 5;
vector<int> adj[N];
int cnt_adj[N];
int ans[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;

  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[v].push_back(u);
    ++cnt_adj[u];
  }

  set<int> curr;
  for (int i = 1; i <= n; ++i) {
    if (cnt_adj[i] == 0) {
      curr.emplace(i);
    }
  }

  int nxt = n;
  while (!curr.empty()) {
    int node = *curr.rbegin();
    curr.erase(node);

    ans[node] = nxt--;

    for (int v : adj[node]) {
      if (--cnt_adj[v] == 0) {
        curr.emplace(v);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << ' ';
  }

}
