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

const int N = 2e5 + 5;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  vector<int> v(n);

  for (int& x : v) {
    cin >> x;
  }

  sort(all(v));

  int mn = 0;
  int last = -10;

  for (int x : v) {
    if (abs(x - last) > 1) {
      last = x + 1;
      ++mn;
    }
  }

  int mx = 0;
  last = -10;

  for (int x : v) {
    if (x - last > 1) {
      last = x - 1;
      ++mx;
    } else if (x - last == 1) {
      last = x;
      ++mx;
    } else if (x == last) {
      last = x + 1;
      ++mx;
    }
  }

  cout << mn << " " << mx << endl;

  return 0;
}