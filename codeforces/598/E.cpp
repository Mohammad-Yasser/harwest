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
typedef double Double;

const int N = 31;
const int MX = 51;
const int OO = 1e9 / 2;
int memo[N][N][MX];

int solve(int width, int length, int k) {
  if (width > length) {
    swap(width, length);
  }
  if (k == 0 || k == width * length) return 0;
  if (k < 0 || k > width * length) return OO;

  int& res = memo[width][length][k];
  if (res != -1) return res;
  res = OO;
  for (int s = 0; s < 2; ++s) {
    for (int i = 1; i <= width - i; ++i) {
      for (int j = 0; j <= k; ++j) {
        res = min(res, length * length + solve(i, length, j) +
                           solve(width - i, length, k - j));
      }
    }
    swap(width, length);
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

  memset(memo, -1, sizeof memo);
  int t;
  cin >> t;

  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    cout << solve(n, m, k) << endl;
  }
  return 0;
}