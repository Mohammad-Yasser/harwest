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
typedef pair<int, int> Cell;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  int cnt_1 = 0, cnt_2 = 0;

  while (n--) {
    int x;
    cin >> x;
    cnt_1 += (x == 1);
    cnt_2 += (x == 2);
  }

  if (cnt_2 != 0) {
    cout << 2 << " ";
    --cnt_2;
  }

  if (cnt_1 != 0) {
    cout << 1 << " ";
    --cnt_1;
  }

  while (cnt_2--) {
    cout << 2 << " ";
  }

  while (cnt_1--) {
    cout << 1 << " ";
  }

  cout << endl;

}
