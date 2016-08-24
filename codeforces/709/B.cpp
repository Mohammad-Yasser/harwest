#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int x[N];

int main() {
  int n, a;
  cin >> n >> a;
  for (int i = 0; i < n; ++i) cin >> x[i];
  sort(x, x + n);
  if (n == 1) {
    cout << 0;
    return 0;
  }
  int ans = 1e9;
  for (int i = 0; i < 2; ++i)
    for (int j = i; j < i + n - 1; ++j) {
      ans = min(ans, abs(a - x[j]) + 2 * min(x[i + n - 2] - x[j], x[j] - x[i]) +
                         max(x[i + n - 2] - x[j], x[j] - x[i]));
    }

  cout << ans;
}
