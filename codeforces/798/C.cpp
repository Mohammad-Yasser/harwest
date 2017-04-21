#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cout << "YES\n";

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int g = a[0];

  for (int i = 1; i < n; ++i) {
    g = __gcd(g, a[i]);
  }

  if (g > 1) {
    cout << 0;
    return 0;
  }

  int res = 0;

  for (int i = n - 2; i >= 0; --i) {
    if (a[i] & a[i + 1] & 1) {
      a[i] ^= 1;
      a[i + 1] ^= 1;

      ++res;
    }
  }

  for (int i = 0; i < n; ++i) {
    res += 2 * (a[i] & 1);
  }

  cout << res;

  return 0;
}
