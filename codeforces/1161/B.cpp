#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

// gp_hash_table<int, int> table;

const int N = 2e5 + 5;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> segments(m);

  for (auto& seg : segments) {
    cin >> seg.first >> seg.second;
    --seg.first, --seg.second;
    if (seg.first > seg.second) {
      swap(seg.first, seg.second);
    }

  }

  sort(segments.begin(), segments.end());

  for (int i = 1; i < n; ++i) {
    if (n % i != 0) continue;

    vector<pair<int, int>> rotated(m);
    for (int j = 0; j < m; ++j) {
      rotated[j] = {(segments[j].first + i) % n , (segments[j].second + i) % n};
      if (rotated[j].first > rotated[j].second) {
        swap(rotated[j].first , rotated[j].second);
      }

    }
    sort(rotated.begin(), rotated.end());
    if (segments == rotated) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";

}
