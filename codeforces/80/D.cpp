#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
typedef long long Long;
typedef long double Double;

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
// p >= 4q

Double solve(Double a, Double b) {
  if (b == 0) {
    return 1;
  }
  if (a == 0) {
    return 0.5;
  }
  Double original_b = b;
  Double original_a = a;
  b = min(b, a / 4);
  Double res = (a - 4 * b) / a;
  a = 4 * b;
  // Integrate the function f(a): the probability of q being good if p == a.
  res += a * a / (8 * original_b) / original_a;
  res = 0.5 * (res + 1);
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
    Double a, b;
    cin >> a >> b;
    cout << fixed << setprecision(10) << solve(a, b) << endl;
  }

  return 0;
}