#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<int> adj[N];

short food[N];

void dfs(int u, short f) {
  if (food[u] != 0) return;
  food[u] = f;
  for (int v : adj[u]) {
    dfs(v, f ^ 3);
  }
}

pair<int, int> frds[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    frds[i] = {a , b};
    adj[a].push_back(b);
    adj[b].push_back(a);

    adj[2 * i].push_back(2 * i + 1);
    adj[2 * i + 1].push_back(2 * i);
  }

  for (int i = 0; i < 2 * n; ++i) {
    dfs(i, 1);
  }

  for (int i = 0; i < n; ++i) {
    cout << food[frds[i].first] << ' ' << food[frds[i].second] << '\n';
  }

}
