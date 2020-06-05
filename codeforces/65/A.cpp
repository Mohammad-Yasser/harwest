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

  Long a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  Long num = b * d * f;
  Long den = a * c * e;
  if (num > den || a == 0 && b != 0 && d != 0 ||
      e == 0 && f != 0 && b != 0 && d != 0 || c == 0 && d != 0) {
    cout << "Ron" << endl;
  } else {
    cout << "Hermione" << endl;
  }
  return 0;
}