#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const double PI = acos(-1);

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif



  double n , r;
  cin >> n >> r;

  double angle = 2 * PI / n;

  // x = (x + r) sin(angle/2)
  // x = x * sin(angle/2) + r * sin(angle/2)
  // x (1 - sin(angle/2)) = r * sin(angle/2)
  // x = r * sin(angle/2) / (1 - sin(angle/2))

  cout << fixed << setprecision(10) << r * sin(angle/2) / (1 - sin(angle/2));

}
