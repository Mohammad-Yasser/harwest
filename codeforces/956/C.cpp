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
#define rep(i, a, b) for (int i = a; i < int(b); ++i)

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

  int n;
  cin >> n;
  vector<int> v(n);
  cin >> v;
  vector<int> cnt_distinct(n);

  for (int i = 0; i < n; ++i) {
    cnt_distinct[i] = v[i] + 1;
    if (i != 0) {
      cnt_distinct[i] = max(cnt_distinct[i], cnt_distinct[i - 1]);
    }
  }
  for (int i = n - 2; i >= 0; --i) {
    cnt_distinct[i] = max(cnt_distinct[i], cnt_distinct[i + 1] - 1);
  }

  Long res = 0;
  for (int i = 0; i < n; ++i) {
    res += cnt_distinct[i] - v[i] - 1;
  }

  cout << res << endl;

  return 0;
}