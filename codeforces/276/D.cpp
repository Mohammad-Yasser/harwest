#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
#define popCnt(x) (__builtin_popcountll(x))

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  Long l, r;
  cin >> l >> r;

  for (int i = 60; i >= 0; --i) {
    if (((r >> i) & 1) && ((~l >> i) & 1)) {
      cout << (1LL << (i + 1)) - 1;
      return 0;
    }
  }

  cout << 0;

}
