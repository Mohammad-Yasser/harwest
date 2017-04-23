#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

const int N = 81;
const int OO = 1e9;

int memo[N][N][N][2];

vector<pair<int, int>> adj[N]; // {v , cost}

int Solve(int left, int right, int k, bool left_last) {
  if (right - left < k) return OO;
  if (k == 0) return 0;

  int& res = memo[left][right][k][left_last];

  if (res != -1) return res;
  res = OO;

  int last = (left_last ? left : right);

  for (auto v : adj[last]) {
    if (left <= v.first && v.first <= right) {
      int cost = OO;
      if (left_last) {
        cost = min(cost, Solve(left + 1, v.first, k - 1, false));
        cost = min(cost, Solve(v.first, right, k - 1, true));
      } else {
        cost = min(cost, Solve(left, v.first, k - 1, false));
        cost = min(cost, Solve(v.first, right - 1, k - 1, true));
      }
      res = min(res, cost + v.second);
    }
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  memset(memo, -1, sizeof memo);

  int n, k;
  cin >> n >> k;

  int m;
  cin >> m;

  while (m--) {
    int u, v, c;
    cin >> u >> v >> c;
    if (u == v) continue;

    adj[u].emplace_back(v, c);
  }

  int res = OO;

  for (int i = 1; i <= n; ++i) {
    res = min(res, Solve(i, n, k - 1, true));
    res = min(res, Solve(1, i, k - 1, false));
  }

  if (res == OO) res = -1;

  cout << res << '\n';

  return 0;
}
