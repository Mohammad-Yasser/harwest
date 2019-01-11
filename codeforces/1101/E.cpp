#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  int mx_x = 0;
  int mx_y = 0;

  while (n--) {
    char c;
    int x, y;
    cin >> c >> x >> y;
    if (x > y) {
      swap(x, y);
    }
    if (c == '?') {
      if (mx_x <= x && mx_y <= y) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      mx_x = max(mx_x, x);
      mx_y = max(mx_y, y);
    }
  }

}
