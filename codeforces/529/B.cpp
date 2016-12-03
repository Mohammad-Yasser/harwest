#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1003;

int w[N], h[N];

int main() {
//  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("test.in", "rt", stdin);
#endif

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> h[i];
  }

  int mn = INT_MAX;
  for (int height = 1; height < N; ++height) {
    int width = 0;
    vector<int> can;
    int used = 0;
    for (int i = 0; i < n; ++i) {
      int a = w[i], b = h[i];
      bool swapped = false;
      if (a > b) {
        swap(a, b);
        swapped = true;
      }
      if (b > height) {
        if (a > height) {
          goto nxt;
        }
        width += b;
        if (!swapped) ++used;
      } else {
        width += a;
        if (swapped) {
          can.emplace_back(b - a);
          ++used;
        }
      }
    }

    sort(can.begin(), can.end());
    for (int i = 0; i < (int) can.size() && used > n / 2; ++i, --used) {
      width += can[i];
    }
    if (used > n / 2) {
      goto nxt;
    }
    mn = min(mn, width * height);
    nxt: ;
  }
  cout << mn;

  return 0;
}
