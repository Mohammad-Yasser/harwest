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

const int N = 2e5 + 5;
const int MOD = 1000000007;

struct DSU {
  int parent[N];

  void init() {
    for (int i = 0; i < N; ++i) {
      parent[i] = i;
    }
  }

  int getSame(int x) {
    return 2 * x;
  }

  int getNot(int x) {
    return 2 * x + 1;
  }

  int getRoot(int x) {
    if (x == parent[x]) return x;
    return parent[x] = getRoot(parent[x]);
  }

  bool join(int a, int b, bool c) {
    int same_a = getRoot(getSame(a));
    int same_b = getRoot(getSame(b));

    int opp_a = getRoot(getNot(a));
    int opp_b = getRoot(getNot(b));

    if (c) {
      if (same_a == opp_b) return false;
      parent[same_a] = same_b;
      parent[opp_a] = opp_b;
    } else {
      if (same_a == same_b) return false;
      parent[same_a] = opp_b;
      parent[opp_a] = same_b;
    }
    return true;
  }

} dsu;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;

  dsu.init();

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (!dsu.join(a, b, c)) {
      cout << 0 << endl;
      return 0;
    }
  }

  set<int> comps;
  for (int i = 1; i <= n; ++i) {
    int same_i = dsu.getRoot(dsu.getSame(i));
    int not_i = dsu.getRoot(dsu.getNot(i));
    comps.insert(same_i);
    comps.insert(not_i);
  }

  assert(comps.size() % 2 == 0);
  int pw2 = comps.size() / 2 - 1;
  int res = 1;
  while (pw2--) {
    res = 2LL * res % MOD;
  }
  cout << res << endl;

}
