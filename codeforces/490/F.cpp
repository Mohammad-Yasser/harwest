#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
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
typedef long double Double;
typedef vector<int> vi;

const int N = 6003;

int r[N];

vector<int> adj[N];
short memo[N][N];

short solve(int node, int parent, int prev) {
  short& res = memo[node][prev];
  if (res != -1) return res;
  res = r[node] > r[prev];
  for (int v : adj[node]) {
    if (v == parent) continue;
    res = max(res, solve(v, node, prev));
  }
  if (r[node] > r[prev]) {
    for (int v : adj[node]) {
      if (v == parent) continue;
      res = max(res, (short)(1 + solve(v, node, node)));
    }
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

  memset(memo, -1, sizeof memo);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> r[i];
  }

  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].emplace_back(y), adj[y].emplace_back(x);
  }

  int res = 0;

  for (int i = 1; i <= n; ++i) {
    res = max(res, 1 + solve(i, -1, i));
  }

  cout << res << endl;

  return 0;
}
