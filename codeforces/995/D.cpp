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

const int N = 19;

double c[1 << N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, r;
  cin >> n >> r;
  double sum = 0;
  for (int i = 0; i < (1 << n); ++i) {
    cin >> c[i];
    sum += c[i];
  }

  cout << fixed << setprecision(10) << sum / (1 << n) << endl;

  while (r--) {
    int ind , val;
    cin >> ind >> val;
    sum -= c[ind];
    sum += (c[ind] = val);
    cout << fixed << setprecision(10) << sum / (1 << n) << endl;
  }


}
