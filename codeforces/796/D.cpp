#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

const int N = 3e5 + 5;

vector<pair<int, int>> adj[N];

bool is_station[N];

int nearest_station[N];

bool removed[N];

void Solve() {
  queue<pair<int, int>> q; // {node , station}
  for (int i = 0; i < N; ++i) {
    if (is_station[i]) {
      q.emplace(i, i);
    }
  }

  while (!q.empty()) {
    int sz = q.size();
    while (sz--) {
      auto curr = q.front();
      q.pop();
      if (nearest_station[curr.first] != 0) continue;
      nearest_station[curr.first] = curr.second;

      for (auto v : adj[curr.first]) {
        q.emplace(v.first, curr.second);
      }
    }
  }

  vector<int> res;

  for (int i = 0; i < N; ++i) {
    if (nearest_station[i] == 0) continue;
    for (auto v : adj[i]) {
      if (removed[v.second]) continue;
      if (nearest_station[v.first] != nearest_station[i]) {
        removed[v.second] = true;
        res.push_back(v.second);
      }
    }
  }

  cout << res.size() << '\n';
  for (int x : res) {
    cout << x << ' ';
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n, k, d;

  cin >> n >> k >> d;

  while (k--) {
    int x;
    cin >> x;
    is_station[x] = true;
  }

  k = count(is_station, is_station + N, true);

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;

    adj[u].emplace_back(v, i);
    adj[v].emplace_back(u, i);
  }



  Solve();
}
