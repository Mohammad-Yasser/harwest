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

Long solve(Long n, Long ind) {
  if (ind % 2 == 1) return (ind + 1) / 2;
  if (ind > n) {
    return solve(n - (ind - 1) / 2, 2) + n - (ind - 1) / 2;
  }
  return solve((n + 1) / 2, (n + 1) / 2 - n / 2 + ind / 2) + n / 2;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  Long n;
  int q;
  cin >> n >> q;
  while (q--) {
    Long x;
    cin >> x;
    cout << solve(n , x) << endl;
  }

}
