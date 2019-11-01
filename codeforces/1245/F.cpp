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

const int N = 33;

Long l, r;

Long memo[N][2][2][2][2];

Long solve(int ind, bool first_equal_l, bool first_equal_r, bool second_equal_l,
  bool second_equal_r) {
  if (ind == -1) return 1;
  auto& res =
    memo[ind][first_equal_l][first_equal_r][second_equal_l][second_equal_r];
  if (res != -1) return res;
  res = 0;

  bool l_bit = ((l >> ind) & 1);
  bool r_bit = ((r >> ind) & 1);

  for (int first = 0; first < 2; ++first) {
    for (int second = 0; second < 2; ++second) {
      if (first + second == 2) continue;
      if (first < l_bit && first_equal_l) continue;
      if (first > r_bit && first_equal_r) continue;

      if (second < l_bit && second_equal_l) continue;
      if (second > r_bit && second_equal_r) continue;

      res += solve(ind - 1, first_equal_l && first == l_bit,
        first_equal_r && first == r_bit, second_equal_l && second == l_bit,
        second_equal_r && second == r_bit);
    }
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

  int t;
  cin >> t;

  while (t--) {
    memset(memo, -1, sizeof memo);
    cin >> l >> r;
    cout << solve(32, true, true, true, true) << endl;
  }
}
