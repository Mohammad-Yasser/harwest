#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
 *
 if x == 2 * a:

 z = a + y + 2 * a * y
 (2 * a + 1) * (y + 0.5) = 2 * a * y + y + a + 0.5
 z + 0.5 = a + y + 2 * a * y + 0.5
 z + 0.5 = (2 * a + 1) * (y + 0.5)
 2 * z + 1 = (2 * a + 1) * (2 * y + 1)

 Hence, (2 * z + 1) mustn't have an odd factor,
 so, it must be prime. --> 1

 if x == 2 * a + 1:

 z = a + y + (2 * a + 1) * y
 z = a + 2 * y + 2 * a * y
 (a + 1) * (2 * y + 1) = 2 * y * a + 2 * y + a + 1
 z + 1 = a + 2 * y + 2 * a * y + 1
 z + 1 = (a + 1) * (2 * y + 1)

 Hence, (z + 1) mustn't have an odd factor, i.e z + 1 == 2 ^ i --> 2


 From 1 & 2:

 2 * (2 * i - 1) + 1 must be prime.
 2 ^ (i + 1) - 1 must be prime. (It's called mersenne prime.)


 */

int mersenne[] = { 2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127, 521, 607, 1279,
  2203, 2281, 3217, 4253, 4423, 9689, 9941, 11213, 19937, 21701, 23209, 44497,
  86243, 110503, 132049, 216091, 756839, 859433, 1257787, 1398269, 2976221,
  3021377, 6972593, 13466917, 20996011, 24036583, 25964951, 30402457, 32582657,
  37156667 };

const int MOD = 1000000007;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;
  --n;
  n = mersenne[n];
  --n;

  int res = 1;
  while (n--) {
    res = (2 * res) % MOD;
  }

  res = (res + MOD - 1) % MOD;

  cout << res;
}
