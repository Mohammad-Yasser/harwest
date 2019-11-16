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

  int n , m;
  cin >> n >> m;

  vector <int> val(n);

  for (int& x : val) {
    cin >> x;
  }
  sort(val.begin(), val.end());


  vector <Long> sum(m);
  Long res = 0;

  for (int i = 0 ; i < n ; ++i) {
    int x = val[i];
    sum[i % m] += x;
    res += sum[i % m];
    cout << res << " ";
  }

}
