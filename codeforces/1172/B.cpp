#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

// gp_hash_table<int, int> table;

const int N = 2e5 + 5;
const int MOD = 998244353;

vector<int> adj[N];

int fact[N];

void buildFact() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = 1LL * fact[i - 1] * i % MOD;
  }
}

int res[N];
int sz[N];

int solve(int node, int parent = -1) {
  int res = 1;
  int children = 1;
  sz[node] = 1;

  for (int v : adj[node]) {
    if (v == parent) continue;
    ++children;
    res = 1LL * res * solve(v, node) % MOD;
    sz[node] += sz[v];
  }

  if (node == 1) {
    int cycles_res = 1;
    for (int v : adj[node]) {
      cycles_res += sz[v];
    }
    res = 1LL * res * fact[children - 1] % MOD;
    res = 1LL * res * cycles_res % MOD;
  } else {
    res = 1LL * res * fact[children] % MOD;
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

  buildFact();

  int n;
  cin >> n;

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  cout << solve(1, -1) << endl;
}

