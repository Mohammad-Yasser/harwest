#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 3e5 + 5;

int n;
int arr[N];
int acc[N];

int occ[1 << 21][2];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n;

  ++occ[0][0];
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    acc[i] = arr[i] ^ acc[i - 1];
    ++occ[acc[i]][i & 1];
  }

  Long res = 0;

  for (int i = 0; i < (1 << 21); ++i) {
    for (int j = 0; j < 2; ++j) {
      Long tmp = occ[i][j];
      res += tmp * (tmp - 1) / 2;
    }
  }

  cout << res;

}
