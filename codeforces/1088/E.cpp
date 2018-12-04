#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 3e5 + 5;

vector<int> adj[N];
Long w[N];

Long max_sum = INT_MIN;
int cnt;

Long dfs(int node, int parent, bool cnt_on) {
  Long res = w[node];
  for (int child : adj[node]) {
    if (child == parent) continue;
    Long tmp = dfs(child, node, cnt_on);
    if (cnt_on && tmp == max_sum) continue;
    res += max(0LL, tmp);
  }
  if (res == max_sum && cnt_on) {
    ++cnt;
  }
  max_sum = max(max_sum, res);
  return res;
}

void solve() {
  dfs(1, -1, false);
  dfs(1, -1, true);
  cout << cnt * max_sum << " " << cnt << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
  }

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  solve();

}
