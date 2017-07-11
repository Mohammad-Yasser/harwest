#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << ' ' << x << endl;

typedef long long Long;


int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n, k;
  cin >> n >> k;

  int floor = (n - 1) / k;
  int rem = (n - 1) % k;

  cout << 2 * floor + (rem > 0) + (rem > 1) << '\n';

  int centroid = 1;
  int nxt = 2;
  for (int i = 0; i < k; ++i) {
    int length = floor + (i < rem);
    cout << centroid << ' ' << nxt << '\n';
    --length;

    while (length--) {
      cout << nxt << ' ' << nxt + 1 << '\n';
      ++nxt;
    }
    ++nxt;
  }

  return 0;
}
