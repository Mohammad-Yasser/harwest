#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 1e5 + 5;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  int a, b, x = 1e5;

  bool dec = true;

  while (n--) {
    cin >> a >> b;
    if (a != b) {
      cout << "rated";
      return 0;
    }
    dec &= (a <= x);
    x = a;
  }

  if (dec) {
    cout << "maybe";
  } else {
    cout << "unrated";
  }

}

