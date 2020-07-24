#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

bool winning(int x, int y) { return y % 2 == 1 || x % 4 != 3; }

const int B = 30;
int cnt[B];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  while (t--) {
    memset(cnt, 0, sizeof cnt);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      for (int b = B - 1; b >= 0; --b) {
        if ((x >> b) & 1) {
          ++cnt[b];
        }
      }
    }
    int cnt_odd = -1;
    for (int i = B - 1; i >= 0; --i) {
      if (cnt[i] & 1) {
        cnt_odd = cnt[i];
        break;
      }
    }
    if (cnt_odd == -1) {
      cout << "DRAW" << endl;
      continue;
    }
    cout << (winning(cnt_odd, n - cnt_odd) ? "WIN" : "LOSE") << endl;
  }
  return 0;
}