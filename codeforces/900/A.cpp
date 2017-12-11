#include <bits/stdc++.h>

using namespace std;
#define popCnt(x) (__builtin_popcount(x))

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  int cnt = 0;

  for (int i = 0 ; i < n ; ++i) {
    int x, y;
    cin >> x >> y;

    cnt += (x < 0);
  }

  cnt = min(cnt , n - cnt);

  if (cnt <= 1) {
    cout << "Yes";
  } else {
    cout << "No";
  }


}
