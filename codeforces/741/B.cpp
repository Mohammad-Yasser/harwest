#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1003;
const int W = 1003;
vector<vector<int>> comps;

int memo[N][W];

int beauty[N];
int weight[N];

int Solve(int ind, int rem) {
  if (ind == comps.size()) {
    return 0;
  }
  int &ret = memo[ind][rem];
  if (ret != -1) {
    return ret;
  }
  ret = Solve(ind + 1, rem);
  vector<int> &comp = comps[ind];

  int total_w = 0, total_b = 0;
  for (int x : comp) {
    total_w += weight[x];
    total_b += beauty[x];

    if (weight[x] <= rem) {
      ret = max(ret, beauty[x] + Solve(ind + 1, rem - weight[x]));
    }
  }

  if (total_w <= rem) {
    ret = max(ret, total_b + Solve(ind + 1, rem - total_w));
  }

  return ret;
}

vector<int> adj[N];
int comp[N];

void Dfs(int u) {
  if (comp[u]) return;
  comp[u] = comps.size();
  comps.back().push_back(u);

  for (int v : adj[u]) {
    Dfs(v);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("test.in", "rt", stdin);
#endif

  int n, m, w;
  cin >> n >> m >> w;

  for (int i = 0; i < n; ++i) {
    cin >> weight[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> beauty[i];
  }

  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 0; i < n; ++i) {
    if (!comp[i]) {
      comps.push_back(vector<int>());
      Dfs(i);
    }
  }

  memset(memo, -1, sizeof memo);
  cout << Solve(0, w);

  return 0;
}
