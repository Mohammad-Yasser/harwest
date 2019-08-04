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

const int N = 2e5 + 5;

map<int, Long> memo[N];

vector<int> safe;
int n, m;

int first[N], last[N];

Long solve(int i, int j) {
  if (i == n + 1) return 0;
  if (last[i] == 0) {
    if (i == 1) {
      return solve(i + 1, safe[0]) + safe[0] - j + 1;
    }
    return solve(i + 1, j) + 1;
  }

  if (memo[i].count(j)) return memo[i][j];

  Long res = LLONG_MAX;

  // First then last
  Long cost = abs(j - first[i]) + last[i] - first[i] + 1;
  if (i == n) {
    res = min(res, cost - 1);
  }
  auto after = upper_bound(safe.begin(), safe.end(), last[i]);
  auto before = after - 1;
  if (after != safe.end()) {
    res = min(res, cost + solve(i + 1, *after) + abs(*after - last[i]));
  }
  if (after != safe.begin()) {
    res = min(res, cost + solve(i + 1, *before) + abs(*before - last[i]));
  }

  // Last then first
  cost = abs(j - last[i]) + last[i] - first[i] + 1;
  if (i == n) {
    res = min(res, cost - 1);
  }
  after = upper_bound(safe.begin(), safe.end(), first[i]);
  before = after - 1;
  if (after != safe.end()) {
    res = min(res, cost + solve(i + 1, *after) + abs(*after - first[i]));
  }
  if (after != safe.begin()) {
    res = min(res, cost + solve(i + 1, *before) + abs(*before - first[i]));
  }

  return memo[i][j] = res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  fill(first, first + N, 1e7);
  int k, q;
  cin >> n >> m >> k >> q;

  safe.resize(q);

  while (k--) {
    int i, j;
    cin >> i >> j;
    first[i] = min(first[i], j);
    last[i] = max(last[i], j);
  }

  for (int& x : safe) {
    cin >> x;
  }

  while (last[n] == 0) {
    --n;
  }

  sort(safe.begin(), safe.end());

  cout << solve(1, 1) << endl;
}
