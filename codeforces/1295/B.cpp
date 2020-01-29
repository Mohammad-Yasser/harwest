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

  int t;
  cin >> t;

  while (t--) {

    int n, x;
    cin >> n >> x;

    string s;
    cin >> s;

    vector<int> balances(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      balances[i + 1] = balances[i] + (s[i] == '0') - (s[i] == '1');
    }
    if (balances.back() == 0) {
      if (find(balances.begin(), balances.end(), x) != balances.end()) {
        cout << -1 << endl;
      } else {
        cout << 0 << endl;
      }
    } else {
      int res = 0;
      for (int i = 0 ; i < n ; ++i) {
        int b = balances[i];
        int diff = x - b;
        res += (diff % balances.back() == 0 && diff / balances.back() >= 0);
      }
      cout << res << endl;
    }
  }

}
