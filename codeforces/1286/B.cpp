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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2003;
vector<int> adj[N];

int a[N];
int c[N];
int sz[N];
int n;

bool solve(int node, int start = 1) {
  sz[node] = 0;
  for (int child : adj[node]) {
    if (!solve(child, start + sz[node])) return false;
    sz[node] += sz[child];
  }
  if (c[node] > sz[node]) return false;
  a[node] = start + c[node];
  for (int i = 1 ; i <= n ; ++i) {
    if (i != node && a[i] >= a[node]) {
      ++a[i];
    }
  }
  ++sz[node];
  return true;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n;
  int root = 1;
  for (int i = 1; i <= n; ++i) {
    int p;
    cin >> p >> c[i];
    if (p == 0) {
      root = i;
    } else {
      adj[p].push_back(i);
    }
  }

  if (!solve(root)) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
  }

}

