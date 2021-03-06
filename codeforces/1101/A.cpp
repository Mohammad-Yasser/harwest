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

  int q;
  cin >> q;

  while (q--) {
    Long l, r, d;
    cin >> l >> r >> d;
    if (d < l) {
      cout << d << endl;
      continue;
    }
    cout << (r / d + 1) * d << endl;
  }
}
