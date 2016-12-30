#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  int n, k;
  cin >> n >> k;

  int ans = 0;
  int curr = 0;

  for (int i = 1; i <= n; ++i) {
    curr += 5 * i;
    if (curr + k > 240) {
      break;
    }
    ++ans;
  }

  cout << ans;

}
