#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

const int N = 2e3 + 5;
Double p;

Double memo[N][N][2][2];
int h;

int x[N];

int nxt_r[N];
int nxt_l[N];
int n;

void buildNxt() {
  nxt_r[n] = n;
  for (int i = n - 1; i >= 1; --i) {
    if (x[i + 1] - x[i] < h) {
      nxt_r[i] = nxt_r[i + 1];
    } else {
      nxt_r[i] = i;
    }
  }

  nxt_l[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (x[i] - x[i - 1] < h) {
      nxt_l[i] = nxt_l[i - 1];
    } else {
      nxt_l[i] = i;
    }
  }
}

int getL(int i, bool prev, bool left) {
  int res = h;
  if (prev) {
    if (left) {
      res = min(res, x[i] - x[i - 1] - h);
    } else {
      res = min(res, x[i + 1] - x[i] - h);
    }
  }
  if (left && i != 1) {
    res = min(res, x[i] - x[i - 1]);
  }
  if (!left && i != n) {
    res = min(res, x[i + 1] - x[i]);
  }
  return res;
}

Double solve(int l, int r, bool prev_l, bool prev_r) {
  if (r < l) return 0;
  auto& res = memo[l][r][prev_l][prev_r];
  if (res != 0) return res;

  // Choose left tree: 0.5
  //    Falls left: p
  res += 0.5 * p * (getL(l, prev_l, true) + solve(l + 1, r, false, prev_r));
  //    Falls right: (1 - p)
  Double tmp;
  if (nxt_r[l] >= r) {
    tmp = x[r] - x[l] + getL(r, prev_r, false);
  } else {
    tmp = x[nxt_r[l]] + h - x[l];
  }
  res += 0.5 * (1 - p) * (tmp + solve(nxt_r[l] + 1, r, true, prev_r));

  // Choose right tree: 0.5
  //    Falls left: p
  if (nxt_l[r] <= l) {
    tmp = x[r] - x[l] + getL(l, prev_l, true);
  } else {
    tmp = x[r] - x[nxt_l[r]] + h;
  }
  res += 0.5 * p * (tmp + solve(l, nxt_l[r] - 1, prev_l, true));
  //    Falls right: (1 - p)
  res +=
      0.5 * (1 - p) * (getL(r, prev_r, false) + solve(l, r - 1, prev_l, false));
  // cout << l << " " << r << " " << prev_l << " " << prev_r << " " << res <<
  // endl;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n >> h >> p;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  sort(x + 1, x + 1 + n);
  buildNxt();
  cout << fixed << setprecision(10) << solve(1, n, false, false) << endl;
  return 0;
}
