#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 2003;

int cost[N][N];
int nearest[N];

Long dist[N];

int n;
int min_cost = 1e9 + 1;

void Dijkstra() {
  memset(dist, 0x3f, sizeof dist);

  for (int i = 1; i <= n; ++i) {
    dist[i] = 2 * (nearest[i] - min_cost);
  }

  bool vis[N];
  memset(vis, false, sizeof vis);

  for (int iter = 0; iter < n; ++iter) {
    int next = 0;
    for (int i = 1; i <= n; ++i) {
      if (!vis[i] && dist[i] < dist[next]) {
        next = i;
      }
    }
    vis[next] = true;
    for (int i = 1; i <= n; ++i) {
      if (i == next) continue;
      dist[i] = min(dist[i], dist[next] + cost[i][next] - min_cost);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  memset(nearest, 0x3f, sizeof nearest);
  cin >> n;

  for (int i = 1; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      cin >> cost[i][j];
      cost[j][i] = cost[i][j];
      min_cost = min(min_cost, cost[i][j]);

      nearest[i] = min(nearest[i], cost[i][j]);
      nearest[j] = min(nearest[j], cost[i][j]);
    }
  }

  Dijkstra();

  for (int i = 1; i <= n; ++i) {
    cout << dist[i] + 1LL * (n - 1) * min_cost << '\n';
  }

}
