#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

const int N = 3e5 + 3;
const int OO = 1.5e9;

int strengths[N];

vector<int> adj[N];

int max_neigbour[N];

int max_non_neighbour_down[N];
int max_descendant[N];

void BuildDown(int node, int parent) {
  for (int v : adj[node]) {
    if (v == parent) continue;
    BuildDown(v, node);

    max_descendant[node] = max(max_descendant[node], strengths[v]);
    max_descendant[node] = max(max_descendant[node], max_descendant[v]);
    max_non_neighbour_down[node] = max(max_non_neighbour_down[node],
      max_descendant[v]);
  }
}

int max_non_neighbour_up[N];

void BuildUp(int node, int parent) {
  for (int i = 0; i < 2; ++i) {
    int curr_max = max_non_neighbour_up[node];
    if (parent != -1) {
      curr_max = max(curr_max, strengths[parent]);
    }

    for (int v : adj[node]) {
      if (v == parent) continue;
      max_non_neighbour_up[v] = max(max_non_neighbour_up[v], curr_max);

      curr_max = max(curr_max, max_descendant[v]);
      curr_max = max(curr_max, strengths[v]);
    }

    reverse(adj[node].begin(), adj[node].end());
  }

  for (int v : adj[node]) {
    if (v == parent) continue;
    BuildUp(v, node);
  }

}

void Init() {
  fill(max_neigbour, max_neigbour + N, -OO);
  fill(max_non_neighbour_down, max_non_neighbour_down + N, -OO);
  fill(max_descendant, max_descendant + N, -OO);
  fill(max_non_neighbour_up, max_non_neighbour_up + N, -OO);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  Init();

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> strengths[i];
  }

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);

    max_neigbour[u] = max(max_neigbour[u], strengths[v]);
    max_neigbour[v] = max(max_neigbour[v], strengths[u]);
  }

  BuildDown(1, -1);
  BuildUp(1, -1);

  int res = OO;

  for (int i = 1; i <= n; ++i) {
    int tmp = strengths[i];
    tmp = max(tmp, max_non_neighbour_down[i] + 2);
    tmp = max(tmp, max_non_neighbour_up[i] + 2);
    tmp = max(tmp, max_neigbour[i] + 1);

    res = min(res, tmp);
  }

  cout << res << '\n';
  return 0;
}
