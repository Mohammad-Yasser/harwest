#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  for (int pw10 = 1; pw10 < 2e9; pw10 *= 10) {
    for (int p = 1; p < 10; ++p) {
      if (p * pw10 > n) {
        cout << p * pw10 - n;
        return 0;
      }
    }
  }

}
