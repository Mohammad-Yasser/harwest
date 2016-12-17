#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1003;

vector<int> adj[N];

int in_comp[N];
int comp_size[N];

void Dfs(int node, int comp) {
  if (in_comp[node] != 0) return;
  in_comp[node] = comp;
  ++comp_size[comp];
  for (int v : adj[node]) {
    Dfs(v, comp);
  }
}

int countries[N];

inline int nC2(int n) {
  return n * (n - 1) / 2;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; ++i) {
    cin >> countries[i];
  }

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int max_country = 0;
  int ans = 0;
  for (int i = 0; i < k; ++i) {
    Dfs(countries[i], countries[i]);
    if (comp_size[countries[i]] > max_country) {
      max_country = comp_size[countries[i]];
    }
    ans += nC2(comp_size[countries[i]]);
  }

  ans -= nC2(max_country);

  for (int i = 1; i <= n; ++i) {
    if (in_comp[i] != 0) continue;
    Dfs(i, i);
    max_country += comp_size[i];
  }

  ans += nC2(max_country);

  cout << ans - m;

}
