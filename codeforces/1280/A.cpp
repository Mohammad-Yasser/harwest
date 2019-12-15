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

const int MOD = round(1e9 + 7);
string s;
int x;

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
    cin >> x >> s;
    int sz = s.size();
    for (int l = 0; l < x;) {
      ++l;
      Long k = (s[l - 1] - '1');

      for (int i = 0; i < k; ++i) {
        for (int j = l; j < sz && s.size() < x; ++j) {
          s += s[j];
        }
      }
      sz = ((1LL * sz + k * (sz - l)) % MOD + MOD) % MOD;
    }
    cout << sz << endl;
  }
}
