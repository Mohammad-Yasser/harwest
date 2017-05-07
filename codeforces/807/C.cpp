#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const Long OO = 1e18 + 5;

Long x, y, p, q;

bool Check(Long c) {
  /*
   a = c * p - x
   b = c * q - y

   c * p - x >= 0
   c * p >= x
   c >= (x + p - 1) / p

   c * q - y >= c * p - x
   c * q - c * p >= y - x
   c * (q - p) >= y - x
   c >= (y - x + q - p - 1) / (q - p)
   */

  bool first = false;

  if (p == 0) {
    first = (x == 0);
  } else {
    first = (c >= (x + p - 1) / p);
  }

  bool second = false;

  if (q == p) {
    second = (x == y);
  } else {
    second = (c >= (y - x + q - p - 1) / (q - p));
  }

  return first && second;
}

Long Solve() {
  Long low = 1, high = OO, mid, ans = -1;

  while (low <= high) {
    mid = (low + high) / 2;

    if (Check(mid)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  while (n--) {
    cin >> x >> y >> p >> q;

    Long res = Solve();

    if (res != -1) {
      res = res * q - y;
    }

    cout << res << '\n';
  }
}

