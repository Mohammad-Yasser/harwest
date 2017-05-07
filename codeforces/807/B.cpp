#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

bool Check(int x , int p) {
  int i = (x / 50) % 475;
  for (int a = 0 ; a < 25 ; ++a) {
    i = (i * 96 + 42) % 475;
    if (26 + i == p) {
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int p, x, y;
  cin >> p >> x >> y;

  for (int succ = 0; succ <= 1000; ++succ) {
    for (int unc = 0; unc <= 1000; ++unc) {
      int curr = x + succ * 100 - unc * 50;
      if (curr < y) continue;

      if (Check(curr , p)) {
        cout << succ;
        return 0;
      }
    }
  }

}

