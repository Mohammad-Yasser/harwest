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

const int N = 2e5 + 5;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
//  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;

  int first_row = 1, last_row = n;
  while (first_row < last_row) {
    for (int i = 1; i <= m; ++i) {
      cout << first_row << " " << i << endl;
      cout << last_row << " " << m - i + 1 << endl;
    }

    first_row += 1;
    last_row -= 1;
  }

  if (first_row == last_row) {
    int left = 1, right = m;
    for (int i = 1; i <= m; ++i) {
      cout << first_row << " " << ((i & 1) ? left++ : right--) << endl;
    }
  }

}
