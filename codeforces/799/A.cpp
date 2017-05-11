#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n, t, k, d;
  cin >> n >> t >> k >> d;

  for (int i = 1; i < 1e7; ++i) {
    int t1 = i / t * k;
    int t2 = 0;
    if (i > d) {
      t2 = (i - d) / t * k + t1;
    }
    if (t1 >= n) {
      cout << "NO";
      return 0;
    }
    if (t2 >= n) {
      cout << "YES";
      return 0;
    }
  }

}
