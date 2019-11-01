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

typedef long double Double;

const int N = 10;

Double memo[N][N];
int h[N][N];

Double solve(int i, int j) {
  if (i == 0 && j == 0) return 0;
  auto& res = memo[i][j];
  if (res == res) return res;

  res = 0;
  int curr_i = i, curr_j = j;
  int invalid = 0;
  for (int steps = 1; steps <= 6; ++steps) {
    if (curr_i & 1) {
      if (curr_j + 1 == N) {
        --curr_i;
      } else {
        ++curr_j;
      }
    } else {
      if (curr_j == 0) {
        --curr_i;
      } else {
        --curr_j;
      }
    }
    if (curr_i == -1) {
      ++invalid;
    } else {
      res += min(solve(curr_i, curr_j),
        solve(curr_i - h[curr_i][curr_j], curr_j));
    }
  }
  res = (res / 6 + 1) / (1 - invalid / 6.0);

  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> h[i][j];
    }
  }

  memset(memo, -1, sizeof memo);

  cout << fixed << setprecision(10) << solve(9, 0) << endl;

}
