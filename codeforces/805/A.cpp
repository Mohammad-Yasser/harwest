#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int MOD = round(1e9 + 7);

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int l, r;

  cin >> l >> r;

  if (l == r) {
    cout << l;
    return 0;
  }

  cout << 2;
}

