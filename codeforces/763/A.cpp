#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int color[N];
vector<int> adj[N];

int memo[2 * N];
pair<int, int> edges[2 * N];
int cnt = 0;
int Get(int edge) {
  int node = edges[edge].first;
  int parent = edges[edge].second;

  int &res = memo[edge];

  if (res != -1) {
    return res;
  }

  assert(++cnt < 2 * N);

  res = color[node];

  for (int v : adj[node]) {
    if (v == (edge ^ 1)) continue;
    if (res != Get(v)) {
      res = 0;
      break;
    }
  }

//  cout << node << ' ' << parent << ' ' << res << endl;

  return res;

}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  int n;
  cin >> n;

  memset(memo, -1, sizeof memo);

  for (int i = 0; i + 1 < n; ++i) {
    int u, v;
    cin >> u >> v;

    edges[2 * i] = make_pair(v, u);
    edges[2 * i + 1] = make_pair(u, v);

    adj[u].push_back(2 * i);
    adj[v].push_back(2 * i + 1);
  }

  for (int i = 1; i <= n; ++i) {
    cin >> color[i];
  }

  for (int i = 1; i <= n; ++i) {
    bool can = true;
    for (int v : adj[i]) {
      can &= (Get(v) != 0);
    }
    if (can) {
      cout << "YES\n";
      cout << i << endl;
      return 0;
    }
  }

  cout << "NO\n";

}
