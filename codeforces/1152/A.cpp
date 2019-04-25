#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

// gp_hash_table<int, int> table;

int cnt[2][2];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n , m ;
  cin >> n >> m;

  while (n--) {
    int x;
    cin >> x;
    ++cnt[0][x & 1];
  }

  while (m--) {
    int x;
    cin >> x;
    ++cnt[1][x & 1];
  }

  int res = min(cnt[0][0] , cnt[1][1]) + min(cnt[0][1] , cnt[1][0]);

  cout << res;

}
