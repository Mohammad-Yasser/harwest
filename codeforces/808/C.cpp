#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 102;

pair<int, int> vol[N];
int res[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n, w;
  cin >> n >> w;

  for (int i = 0; i < n; ++i) {
    cin >> vol[i].first;
    vol[i].second = i;
    res[i] = (vol[i].first + 1) / 2;
    w -= res[i];
  }

  if (w < 0) {
    cout << -1;
    return 0;
  }

  sort(vol, vol + n);

  for (int i = n - 1; i >= 0; --i) {
    int tmp = min(w, vol[i].first - res[vol[i].second]);

    res[vol[i].second] += tmp;
    w -= tmp;
  }

  for (int i = 0 ; i < n ; ++i) {
    cout << res[i] << ' ';
  }

}
