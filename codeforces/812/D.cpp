#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 1e5 + 5;

vector<int> adj[N];
vector<int> rev[N];

void AddEdge(int u, int v) {
  adj[u].push_back(v);
  rev[v].push_back(u);
}

int n, m, k, q;

int has[N];
int size[N];

void BuildSize(int node) {
  size[node] = 1;

  for (int v : rev[node]) {
    BuildSize(v);
    size[node] += size[v];
  }
}

vector<int> q_to[N];
pair<int, int> queries[N];
int ans[N];

bool vis[N];

void Dfs(int node) {
  vis[node] = true;

  for (int q : q_to[node]) {
    if (vis[queries[q].first]) {
      ans[q] = size[queries[q].first];
    }
  }

  for (int v : rev[node]) {
    Dfs(v);
  }

  vis[node] = false;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> n >> m >> k >> q;

  while (k--) {
    int a, b;
    cin >> a >> b;

    if (has[b] != 0) {
      AddEdge(a, has[b]);
    }
    has[b] = a;
  }

  for (int i = 1; i < N; ++i) {
    if (!adj[i].empty()) continue;
    BuildSize(i);
  }

  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;

    queries[i] = {x , has[y]};
    q_to[has[y]].push_back(i);
  }

  for (int i = 1; i < N; ++i) {
    if (!adj[i].empty()) continue;
    Dfs(i);
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << '\n';
  }

}
