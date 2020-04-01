#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int a, b, c, d;

bool solve(int a, int b, int x, int l, int r) {
  if (l == r) {
    return a + b == 0;
  }
  return l <= b - a + x && b - a + x <= r;
}

int main() {
  ios_base::sync_with_stdio(false);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif
  int t;
  cin >> t;

  while (t--) {
    int x, y, x1, y1, x2, y2;

    cin >> a >> b >> c >> d;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    if (solve(a, b, x, x1, x2) && solve(c, d, y, y1, y2)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
