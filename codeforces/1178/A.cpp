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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  int sum_all = 0, sum_c = 0;

  vector<int> res = { 1 };
  int first;

  cin >> first;

  sum_all += first;
  sum_c += first;

  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    sum_all += x;
    if (x * 2 <= first) {
      sum_c += x;
      res.push_back(i);
    }
  }

  if (sum_c * 2 <= sum_all) {
    cout << 0;
    return 0;
  }

  cout << res.size() << endl;
  for (int x : res) {
    cout << x << " ";
  }

}
