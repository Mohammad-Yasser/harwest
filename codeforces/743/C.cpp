#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

/*

 1 / x + 1 / (x + 1) + 1 / (x * (x + 1))
 = (x + 1 + x + 1) / (x * (x + 1))
 = (2 * (x + 1)) / (x * (x + 1))
 = 2 / x

 */

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  int n;
  cin >> n;
  if (n == 1) {
    cout << -1;
    return 0;
  }
  cout << n << ' ' << n + 1 << ' ' << n * (n + 1);
}
