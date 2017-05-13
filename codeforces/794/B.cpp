#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n, h;
  cin >> n >> h;
  double area = 0.5 * h;

  for (int i = 1; i < n; ++i) {
    double x = i * area / n;
    cout << fixed << setprecision(10) << sqrt(2 * h * x) << ' ';
  }

}
