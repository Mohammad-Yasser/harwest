#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2003;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  int n;
  cin >> n;

  int cnt_non_integers = 0;
  int sum = 0;

  for (int i = 0; i < 2 * n; ++i) {
    int x;
    char c;
    cin >> x >> c >> x;
    if (x != 0) {
      ++cnt_non_integers;
    }
    sum -= x;
  }

  int res = 1e9;
  for (int i = max(0, n - (2 * n - cnt_non_integers));
    i <= min(n, cnt_non_integers); ++i) {
    res = min(res, abs(sum + i * 1000));
  }

  cout << fixed << setprecision(3) << res / 1000.0 << '\n';

}
