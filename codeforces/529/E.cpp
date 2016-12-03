#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5003;
const int MX = 10000007;

int arr[N];
bool vis[MX];

int main() {
//  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("test.in", "rt", stdin);
#endif

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    vis[arr[i]] = true;
  }


  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    int mn = -1;

    if (x < MX && vis[x]) {
      cout << 1 << '\n';
      continue;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 1; j <= k; ++j) {
        for (int z = 1; z <= (k - j); ++z) {
          int rem = x - j * arr[i];
          if (rem >= 0 && rem % z == 0 && rem / z < MX && vis[rem / z]
            && (mn == -1 || mn > j + z)) {
            mn = j + z;
          }
        }
      }
    }
    cout << mn << '\n';
  }

  return 0;
}
