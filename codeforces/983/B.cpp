#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

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
typedef long double Double;

const int N = 5001;

int ans[N][N];
int arr[N];

int calc(int i, int j) {
  if (i == j) return arr[i];
  int& res = ans[i][j];
  if (res != -1) return res;
  return res = calc(i, j - 1) ^ calc(i + 1, j);
}

int memo[N][N];

int solve(int i, int j) {
  if (i == j) return arr[i];
  int& res = memo[i][j];
  if (res != -1) return res;
  res = calc(i, j);
  res = max(res, solve(i + 1, j));
  res = max(res, solve(i, j - 1));
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif
  memset(memo, -1, sizeof memo);
  memset(ans, -1, sizeof ans);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  int q;
  cin >> q;

  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    cout << solve(l, r) << endl;
  }
  return 0;
}