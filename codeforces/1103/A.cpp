#include <bits/stdc++.h>
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define getMSB(x) (__builtin_clzll(x))

typedef long long Long;
typedef unsigned long long ULong;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  string s;
  cin >> s;

  int h = 0, v = 0;

  for (char c : s) {
    if (c == '1') {
      cout << "4 " << v + 1 << endl;
      v = (2 + v) % 4;
    } else {
      cout << 1 << " " << h + 1 << endl;
      h = (h + 1) % 4;
    }
  }

}
