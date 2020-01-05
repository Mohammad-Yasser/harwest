#ifndef Local
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

// gp_hash_table<int, int> table;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  int cnt[2] = { n / 2, (n + 1) / 2 };
  vector<int> v(n);
  for (int& x : v) {
    cin >> x;
    if (x == 0) {
      x = -1;
    } else {
      x &= 1;
      --cnt[x];
    }
  }

  vector<int> gaps[2][2];
  int res = 0;
  for (int i = 0; i < n;) {
    int j = i + 1;
    while (j < n && v[j] == -1) {
      ++j;
    }
    if (j == n || v[j] == v[i] || i == 0 && v[i] == -1) {
      bool border = (i == 0 && v[i] == -1 || j == n);
      bool par = (v[i] == -1 ? (j == n ? 1 : v[j]) : v[i]);
      if (j - i - (v[i] != -1) != 0) {
        gaps[par][border].emplace_back(j - i - (v[i] != -1));
      }
    } else {
      ++res;
    }
    i = j;
  }

  for (int par = 0; par < 2; ++par) {
    for (int border = 0; border < 2; ++border) {
      gaps[par][border].push_back(0);
      sort(gaps[par][border].begin(), gaps[par][border].end());
      for (int i = 1; i < gaps[par][border].size(); ++i) {
        gaps[par][border][i] += gaps[par][border][i - 1];
      }
    }
    int mn = 1e9;
    for (int x = 0; x < gaps[par][0].size(); ++x) {
      for (int y = 0; y < gaps[par][1].size(); ++y) {
        int needed = gaps[par][0][x] + gaps[par][1][y];
        if (needed <= cnt[par]) {
          mn = min(mn,
            int(2 * (gaps[par][0].size() - 1 - x) + gaps[par][1].size() - 1 - y));
        }
      }
    }
    res += mn;
  }
  cout << res;

}