#ifndef Local
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

// gp_hash_table<int, int> table;

const int N = 5e5 + 5;

vector<pair<int, Long>> adj[N];

int n, k;
Long memo[N][2];

void init() {
  fill(adj, adj + n + 1, vector<pair<int, Long>>());
  for (int i = 0; i <= n; ++i) {
    memo[i][0] = memo[i][1] = -1;
  }
}

Long solve(int node, int parent, bool taken) {
  Long& res = memo[node][taken];
  if (res != -1) return res;
  res = 0;

  vector<pair<Long, Long>> children;
  for (auto v : adj[node]) {
    if (v.first == parent) continue;
    children.emplace_back(solve(v.first, node, false),
      solve(v.first, node, true) + v.second);
  }
  vector<Long> diff;
  for (auto& child : children) {
    res += child.first;
    if (child.second > child.first) {
      diff.push_back(child.second - child.first);
    }
  }

  sort(diff.rbegin(), diff.rend());
  for (int i = 0; i < min(int(diff.size()), k - taken); ++i) {
    res += diff[i];
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

  int q;

  cin >> q;

  while (q--) {
    cin >> n >> k;
    init();
    for (int i = 1; i < n; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].emplace_back(v, w);
      adj[v].emplace_back(u, w);
    }
    cout << solve(1, -1, false) << endl;
  }

}
