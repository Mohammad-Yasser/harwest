//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse4.1,sse4.2,ssse3,sse3,sse2,sse,avx")
//#pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  Long k, d, t;
  cin >> k >> d >> t;

  d = ((k + d - 1) / d) * d;
  t *= 2;

  double low = 0, high = 1e70, mid;
  for (int i = 0; i < 20000; ++i) {
    mid = (low + high) / 2;
    double num_on = floor(mid / d);
    double rem = min(1.0 * k, mid - num_on * d);
    double x = num_on * k + rem;
    double y = mid - x;
    if (2 * x + y <= t) {
      low = mid;
    } else {
      high = mid;
    }
  }

  cout << fixed << setprecision(10) << low;

}
