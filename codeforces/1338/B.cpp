#ifndef Local
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)

typedef long long Long;
typedef vector<int> vi;

const int N = 1e5 + 5;
vector<int> adj[N];

bool dist[N];

void dfs(int node, int parent) {
  for (int v : adj[node]) {
    if (v == parent) continue;
    dist[v] = !dist[node];
    dfs(v, node);
  }
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

  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }

  vector<int> leaves;
  map<int, int> children_leaves_cnt;

  for (int i = 1; i <= n; ++i) {
    if (adj[i].size() == 1) {
      leaves.emplace_back(i);
      ++children_leaves_cnt[adj[i].back()];
    }
  }

  dfs(leaves.back(), -1);
  int mn = 1;
  for (int x : leaves) {
    if (dist[x]) {
      mn = 3;
    }
  }

  int mx = n - 1;
  for (auto& p : children_leaves_cnt) {
    mx -= max(0, p.second - 1);
  }

  cout << mn << " " << mx << endl;

  return 0;
}