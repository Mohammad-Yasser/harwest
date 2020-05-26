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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int a, b;
  cin >> a >> b;
  string s;
  cin >> s;

  int dx = 0, dy = 0;

  for (char c : s) {
    dx += (c == 'R') - (c == 'L');
    dy += (c == 'U') - (c == 'D');
  }
  if (a == 0 && b == 0) {
    cout << "Yes" << endl;
    return 0;
  }
  int sum_x = dx, sum_y = dy;
  dx = 0, dy = 0;
  for (char c : s) {
    a -= (c == 'R') - (c == 'L');
    b -= (c == 'U') - (c == 'D');
    if (a == 0 && b == 0) {
      cout << "Yes" << endl;
      return 0;
    }
    // cout << a << " " << b << " " << sum_x << " " << sum_y << endl;
    int dv;
    if (sum_x != 0) {
      dv = a / sum_x;
    }
    if (sum_y != 0) {
      dv = b / sum_y;
    }
    if (dv >= 0 && a == dv * sum_x && b == dv * sum_y) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;

  return 0;
}