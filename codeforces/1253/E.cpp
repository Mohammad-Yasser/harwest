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

const int M = 1e5 + 5;
const int N = 81;

int memo[M];
int m;

vector<pair<int, int>> r[M];

int solve(int ind) {
  if (ind > m) return 0;
  int& res = memo[ind];
  if (res != -1) return res;
  res = 1 + solve(ind + 1);
  for (auto& p : r[ind]) {
    res = min(res, p.second + solve(p.first + 1));
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n >> m;

  while (n--) {
    int x, s;
    cin >> x >> s;
    for (int j = 1; j <= x - s; ++j) {
      r[j].emplace_back(x + x - j, max(0, x - j - s));
    }
    for (int j = max(1, x - s); j <= min(m, x + s); ++j) {
      r[j].emplace_back(x + s, 0);
    }
  }

  memset(memo, -1, sizeof memo);
  cout << solve(1) << endl;

}
