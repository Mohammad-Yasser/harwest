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

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}

template <class T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

const int N = 1003;

Long sum_x[N];
Long sum_y[N];

Long sum_row[N];
Long sum_col[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int x;
      cin >> x;
      sum_row[i] += x;
      sum_col[j] += x;
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int r = 0; r <= n; ++r) {
      Long dx;
      if (r < i) {
        dx = 4 * (i - r - 1) + 2;
      } else {
        dx = 4 * (r - i) + 2;
      }
      sum_x[r] += dx * dx * sum_row[i];
    }
  }

  for (int i = 1; i <= m; ++i) {
    for (int r = 0; r <= m; ++r) {
      Long dx;
      if (r < i) {
        dx = 4 * (i - r - 1) + 2;
      } else {
        dx = 4 * (r - i) + 2;
      }
      sum_y[r] += dx * dx * sum_col[i];
    }
  }
  Long res_x = 0, res_y = 0, best = LLONG_MAX;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      Long tmp = sum_x[i] + sum_y[j];
      // cout << i << " " << j << " " << sum_x[i] << " " << sum_y[j] << endl;
      if (tmp < best) {
        best = tmp;
        res_x = i;
        res_y = j;
      }
    }
  }

  cout << best << endl;
  cout << res_x << " " << res_y << endl;

  return 0;
}