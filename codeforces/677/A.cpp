#include <bits/stdc++.h>
using namespace std;
typedef long long ll;




int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  int n ,h;
  cin >> n >> h;

  int ans = n;

  while (n--) {
    int x;
    cin >> x;
    ans += (x > h);
  }

  cout << ans;

}
