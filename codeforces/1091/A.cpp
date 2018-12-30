#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

constexpr int N = 2e5 + 5;


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif


  int y , b , r;
  cin >> y >> b >> r;
  for (int i = 100 ; ; --i) {
    if (i <= y && i + 1 <= b && i + 2 <= r) {
      cout << 3 * (i + 1) << endl;
      return 0;
    }
  }

}
