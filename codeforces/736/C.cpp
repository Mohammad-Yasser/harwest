#include <bits/stdc++.h>
using namespace std;

const int N = 102;
const int K = 23;
const int MOD = 1000000007;

int memo[N][N][N][K];
int k;

vector<int> adj[N];

int Solve(int node, int nearest_down, int nearest_down_bound, int nearest_up,
  int parent) {
  if (nearest_up > k) nearest_up = k + 1;
  if (nearest_down > k && nearest_up > k) return 0;
  if (nearest_down < 0) return 0;
  if (nearest_down_bound < 0) nearest_down_bound = -1;
  if (nearest_down > nearest_down_bound && nearest_down_bound != -1) return 0;

  int &ret = memo[node][nearest_down][nearest_down_bound + 1][nearest_up];
  if (ret != -1) {
    return ret;
  }

  if (nearest_down_bound == -1) nearest_down_bound = N - 1;
  if (nearest_up > k) nearest_down_bound = min(nearest_down_bound, k);

  ret = 0;

  if (adj[node].size() == 1 && parent != -1) {
    ret = (nearest_down == 0) + (nearest_down_bound == N - 1);
    goto end;
  }

  if (nearest_down == 0) {
    int tmp = 1;
    for (int v : adj[node]) {
      if (v == parent) continue;
      tmp = (1LL * tmp * Solve(v, 0, -1, 1, node)) % MOD;
    }

    ret = (ret + tmp) % MOD;
    if (nearest_down_bound == N - 1) nearest_down_bound = -1;
    ret = (ret + Solve(node, 1, nearest_down_bound, nearest_up, parent)) % MOD;
    goto end;
  }

  for (int d = nearest_down; d <= nearest_down_bound; ++d) {
    for (int v : adj[node]) {
      if (v == parent) continue;
      int tmp = Solve(v, d - 1, d - 1, nearest_up + 1, node);
      bool after_v = false;
      for (int other : adj[node]) {
        after_v |= (other == v);
        if (other == v || other == parent) continue;
        tmp = (1LL * tmp
          * Solve(other, d - 1 + after_v, -1, min(d, nearest_up) + 1, node))
          % MOD;
      }
      ret = (ret + tmp) % MOD;
    }
  }

  if (nearest_down_bound == N - 1) {
    int tmp = 1;
    for (int v : adj[node]) {
      if (v == parent) continue;
      tmp *= Solve(v, N - 1, -1, nearest_up + 1, node);
    }
    ret = (ret + tmp) % MOD;
  }

  end: ;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  memset(memo, -1, sizeof memo);
  int n;
  cin >> n >> k;

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  cout << Solve(0, 0, -1, k + 1, -1);

}
