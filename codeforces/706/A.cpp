#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int a, b;
  cin >> a >> b;

  int n;
  cin >> n;
  double ans = 1e17;
  while (n--) {
    int x, y, v;
    cin >> x >> y >> v;
    ans = min(ans, sqrt((x - a) * (x - a) + (y - b) * (y - b)) / v);
  }
  cout << fixed << setprecision(7) << ans;
}
