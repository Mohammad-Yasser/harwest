#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
const int K = 20;

vector<int> adj[N];
int val[N];

ll res;

struct Node {
  ll cnt[K][2];
  Node() {
    memset(cnt, 0, sizeof cnt);
  }
};

bool GetBit(int value, int bit) {
  return (value >> bit) & 1;
}

Node Dfs(int node_id, int parent) {
  Node node;
  vector<Node> children;
  for (int v : adj[node_id]) {
    if (v == parent) continue;
    children.push_back(Dfs(v, node_id));
  }

  Node sum_children;

  for (auto& child : children) {
    for (int i = 0; i < K; ++i) {
      res += (1LL << i) * child.cnt[i][GetBit(val[node_id], i) ^ 1];
      node.cnt[i][0] += child.cnt[i][GetBit(val[node_id], i)];
      node.cnt[i][1] += child.cnt[i][GetBit(val[node_id], i) ^ 1];

      sum_children.cnt[i][0] += child.cnt[i][0];
      sum_children.cnt[i][1] += child.cnt[i][1];
    }
  }

  for (auto& child : children) {
    for (int i = 0; i < K; ++i) {
      sum_children.cnt[i][0] -= child.cnt[i][0];
      sum_children.cnt[i][1] -= child.cnt[i][1];

      res += (1LL << i)
        * (child.cnt[i][0] * sum_children.cnt[i][GetBit(val[node_id], i) ^ 1]
          + child.cnt[i][1] * sum_children.cnt[i][GetBit(val[node_id], i)]);
    }
  }

  for (int i = 0; i < K; ++i) {
    ++node.cnt[i][GetBit(val[node_id], i)];
  }
  res += val[node_id];

  return node;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
  }

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  Dfs(1, -1);

  cout << res << '\n';
}
