#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
typedef long long Long;
typedef double Double;

template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}
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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  Long la, ra, ta;
  Long lb, rb, tb;

  cin >> la >> ra >> ta;
  cin >> lb >> rb >> tb;
  Long res = 0;
  for (int i = 0; i < 2; ++i) {
    Long g = __gcd(ta, tb);
    Long rem_a = la % g;
    Long rem_b = lb % g;
    Long d1 = lb + (rem_a - rem_b + g) % g;
    res = max(res, min(ra - la + 1, rb - d1 + 1));
    swap(la, lb);
    swap(ra, rb);
    swap(ta, tb);
  }

  cout << res << endl;

  return 0;
}