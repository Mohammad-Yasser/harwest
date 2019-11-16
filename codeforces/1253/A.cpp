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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x : v) {
      cin >> x;
    }
    for (int& x : v) {
      int y;
      cin >> y;
      x = y - x;
    }
    int k = 0;
    bool valid = true;
    for (int x : v) {
      valid &= (x >= 0);
      if (x != 0) {
        valid &= (k == 0 || k == x);
        k = x;
      } else {
        if (k != 0) {
          k = -1;
        }
      }
    }
    cout << (valid ? "YES" : "NO") << endl;
  }

}
