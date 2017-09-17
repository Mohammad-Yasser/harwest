#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef long double Double;

const int MOD = 1000000007;
const int N = 200005;
vector<int> comps[N];
vector<int> adj[N];
int ways[N];

int comp_id[N];
bool grey[N];

void buildComps(int node, int id, int parent) {
  if (comp_id[node] != 0) return;
  comp_id[node] = id;
  comps[id].push_back(node);
  grey[node] = true;

  bool pass_p = false;

  for (int v : adj[node]) {
    if (v == parent && !pass_p) {
      pass_p = true;
      continue;
    }
    if (v == node) {
      ways[id] = 1;
    }
    if (grey[v] && ways[id] == 0) {
      ways[id] = 2;
    }
    buildComps(v, id, node);
  }

  grey[node] = false;
}

int solve(int node, int parent) {
  int res = 1;

  for (int v : adj[node]) {
    if (v == parent) continue;
    res = (res + solve(v, node)) % MOD;
  }

  return res;
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

  for (int i = 0; i < n; ++i) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= 2 * n; ++i) {
    buildComps(i, i, -1);
  }

  int res = 1;
  for (int i = 1; i <= 2 * n; ++i) {
    if (comps[i].empty()) continue;
    if (ways[i] == 0) {
      ways[i] = solve(i, -1);
    }
    res = (1LL * res * ways[i]) % MOD;
  }

  cout << res;
}