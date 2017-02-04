#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  int n;
  cin >> n;

  cout << "YES\n";

  while (n--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    x1 = min(x1, x2);
    y1 = min(y1, y2);

    x1 &= 1;
    y1 &= 1;

    cout << (x1 << 1) + y1 + 1 << '\n';
  }

}
