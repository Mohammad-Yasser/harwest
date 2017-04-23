#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

const int N = 1e5 + 5;

int a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  Long res = 0;
  int mn = *min_element(a, a + n);

  for (int i = 0; i < n; ++i) {
    if ((a[i] - mn) % k != 0) {
      cout << -1;
      return 0;
    }
    res += (a[i] - mn) / k;
  }

  cout << res;

  return 0;
}
