#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
typedef long long Long;
typedef long double Double;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  Long a, b, x1, y1, x2, y2;
  cin >> a >> b >> x1 >> y1 >> x2 >> y2;

  a *= 2, b *= 2;

  Long res = 0;

  for (int t = 0; t < 2; ++t) {
    Long s1 = x1 + y1;
    Long s2 = x2 + y2;

    if (s1 > s2) swap(s1, s2);
    if (s1 <= 0) {
      Long tmp = ((-s1 + a - 1) / a + 1) * a;
      s1 += tmp;
      s2 += tmp;
    }

    res = max(res, s2 / a - (s1 - 1) / a);
    y1 *= -1, y2 *= -1;
    swap(a, b);
  }

  cout << res << endl;

  return 0;
}