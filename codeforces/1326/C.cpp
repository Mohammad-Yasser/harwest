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

const int MOD = 998244353;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, k;
  cin >> n >> k;

  int least = n - k + 1;
  cout << 1LL * (least + n) * k / 2 << " ";

  int last = 0;
  Long res = 1;
  bool flag = false;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x >= least) {
      if (flag) {
        res = 1LL * res * (i - last + 1) % MOD;
      }
      flag = true;
      last = i + 1;
    }
  }

  cout << res << endl;

}
