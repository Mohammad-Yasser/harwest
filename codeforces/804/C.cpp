#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 3e5 + 5;

vector<int> nodes[N];
vector<int> types[N];
vector<int> used[N];
vector<int> adj[N];

int color[N];

void Color(int type) {
  for (int node : nodes[type]) {
    used[node].push_back(color[type]);
  }
}

void Dfs(int node, int parent) {
  sort(used[node].rbegin(), used[node].rend());
  int curr_color = 1;

  for (int type : types[node]) {
    if (color[type] != 0) continue;
    while (!used[node].empty() && used[node].back() == curr_color) {
      ++curr_color;
      used[node].pop_back();
    }
    color[type] = curr_color++;
    Color(type);
    used[node].pop_back();
  }

  for (int v : adj[node]) {
    if (v == parent) continue;
    Dfs(v, node);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;

  int mx_node = 1;

  for (int i = 1; i <= n; ++i) {
    int s;
    cin >> s;
    types[i].resize(s);
    for (int& x : types[i]) {
      cin >> x;
      nodes[x].push_back(i);
    }
    if (s > types[mx_node].size()) {
      mx_node = i;
    }
  }

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  Dfs(1, -1);

  cout << max(1, (int) types[mx_node].size()) << '\n';

  for (int i = 1; i <= m; ++i) {
    cout << max(color[i], 1) << ' ';
  }

}