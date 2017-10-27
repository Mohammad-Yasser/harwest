#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n, t;

  cin >> n >> t;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;

    t -= 86400 - x;

    if (t <= 0) {
      cout << i;
      return 0;
    }
  }

}

