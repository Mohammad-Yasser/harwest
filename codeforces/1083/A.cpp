#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = 3e5 + 5;

Long w[N];

vector<pair<int, Long>> adj[N];

vector<Long> mx_up[N];
vector<Long> mx_down[N];

Long res = 0;

Long dfs_up(int node, int parent) {
  res = max(res, w[node]);
  Long mx_tmp = 0;
  for (auto& ch : adj[node]) {
    if (ch.first == parent) continue;
    mx_up[node].push_back(dfs_up(ch.first, node) + w[ch.first] + ch.second);
    mx_tmp = max(mx_tmp, mx_up[node].back());
  }
  return mx_tmp;
}

Long dfs_down(int node, int parent) {
  Long mx_tmp = w[node];
  for (auto& ch : adj[node]) {
    if (ch.first == parent) continue;
    mx_down[node].push_back(dfs_down(ch.first, node) + ch.second + w[node]);
    mx_tmp = max(mx_tmp, mx_down[node].back());
  }

  Long mx_mx_up = 0;
  for (int i = 0; i < mx_up[node].size(); ++i) {
    res = max(res, mx_down[node][i] + mx_mx_up);
    mx_mx_up = max(mx_mx_up, mx_up[node][i]);
  }

  mx_mx_up = 0;
  for (int i = mx_up[node].size() - 1; i >= 0; --i) {
    res = max(res, mx_down[node][i] + mx_mx_up);
    mx_mx_up = max(mx_mx_up, mx_up[node][i]);
  }

  return mx_tmp;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
  }

  for (int i = 1; i < n; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].emplace_back(v, -c);
    adj[v].emplace_back(u, -c);
  }

  dfs_up(1, -1);
  dfs_down(1, -1);

  cout << res;
}

