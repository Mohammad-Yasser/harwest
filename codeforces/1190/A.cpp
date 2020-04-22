#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)

typedef long long Long;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  Long n, m, k;
  cin >> n >> m >> k;

  int res = 0;
  int shift = 1;
  Long prev_page = -1;

  for (int i = 0; i < m; ++i) {
    Long x;
    cin >> x;
    x -= shift;
    Long page = x / k;
    if (page != prev_page) {
      ++res;
      x += shift;
      shift = i + 1;
      x -= shift;
      prev_page = page = x / k;
    }
  }

  cout << res << endl;

  return 0;
}
