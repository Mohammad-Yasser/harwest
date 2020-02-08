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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  string best_handle;
  int res = INT_MIN;

  while (n--) {
    string s;
    int x, y, pts = 0;
    cin >> s >> x >> y;
    pts += x * 100 - y * 50;
    for (int i = 0; i < 5; ++i) {
      int p;
      cin >> p;
      pts += p;
    }
    if (pts > res) {
      res = pts;
      best_handle = s;
    }
  }

  cout << best_handle << endl;
  return 0;
}
