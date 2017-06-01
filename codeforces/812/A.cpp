#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

bool can[4][4];
int shift[3] = { 3, 2, 1 };

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cin >> can[i][j];
    }
  }

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (!can[i][j]) continue;
      if (can[i][3]) {
        cout << "YES";
        return 0;
      }
      int nxt = (i + shift[j]) % 4;
      if (can[nxt][3]) {
        cout << "YES";
        return 0;
      }
    }
  }

  cout << "NO";

}
