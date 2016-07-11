#include <bits/stdc++.h>
using namespace std;

const int N = 3e3;

vector<int> adj[N][2];
int vis[N], vis_ID;
vector<pair<int, int> > distances[N][2];
int res_path[4], res_dist;
int n;

inline void Bfs(int u, bool reverse) {
  ++vis_ID;
  queue<int> q;
  q.push(u);
  vis[u] = vis_ID;
  int curr_dist = 0;
  while (!q.empty()) {
    int sz = q.size();
    while (sz--) {
      int curr = q.front();
      if (curr != u) distances[u][reverse].push_back({curr_dist, curr});
      q.pop();
      for (int v : adj[curr][reverse]) {
        if (vis[v] != vis_ID) vis[v] = vis_ID, q.push(v);
      }
    }
    ++curr_dist;
  }
}

inline void validize(int i, int j, int &x, int &y, bool &valid) {
  while (!valid) {
    if (x >= distances[i][1].size() or y >= distances[j][0].size()) break;
    valid = 1;
    if (distances[i][1][x].second == j) ++x, valid = 0;
    if (distances[j][0][y].second == i) ++y, valid = 0;
  }
}

inline void maximize(int i, int j, int x, int y, int intermediate_dist) {
  int total_dist =
      intermediate_dist + distances[i][1][x].first + distances[j][0][y].first;
  if (total_dist > res_dist) {
    res_dist = total_dist;
    res_path[0] = distances[i][1][x].second;
    res_path[1] = i;
    res_path[2] = j;
    res_path[3] = distances[j][0][y].second;
  }
}

inline void Solve() {
  for (int i = 0; i < n; ++i) {
    Bfs(i, 0);
    Bfs(i, 1);
    sort(distances[i][0].rbegin(), distances[i][0].rend());
    sort(distances[i][1].rbegin(), distances[i][1].rend());
  }

  for (int i = 0; i < n; ++i)
    for (auto j : distances[i][0]) {
      bool valid = 0;
      int x = 0, y = 0;
      validize(i, j.second, x, y, valid);
      if (!valid) continue;

      if (distances[i][1][x].second == distances[j.second][0][y].second) {
        valid = 0;
        ++x;
        validize(i, j.second, x, y, valid);
        if (valid) maximize(i, j.second, x, y, j.first);
        --x;

        ++y;
        valid = 0;
        validize(i, j.second, x, y, valid);
        if (valid) maximize(i, j.second, x, y, j.first);
        continue;
      }
      maximize(i, j.second, x, y, j.first);
    }
}

inline void AddEdge(int u, int v) {
  adj[u][0].push_back(v);
  adj[v][1].push_back(u);
}

int main() {
  cin >> n;
  int m;
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    AddEdge(u, v);
  }

  Solve();

  for (int x : res_path) cout << x + 1 << ' ';
}
