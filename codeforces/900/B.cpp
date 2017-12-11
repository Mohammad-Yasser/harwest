#include <bits/stdc++.h>

using namespace std;
#define popCnt(x) (__builtin_popcount(x))

const int N = 1e5 + 5;

bool vis[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int a, b, c;
  cin >> a >> b >> c;

  a %= b;

  int res = 0;

  while (++res) {
    if (vis[a]) break;
    vis[a] = true;

    a *= 10;

    if (a / b == c) {
      cout << res;
      return 0;
    }

    a %= b;
  }

  cout << -1;

}
