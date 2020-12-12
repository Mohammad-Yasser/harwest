#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("popcnt,abm,mmx,avx2")
#endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define rep(i, l, r) for (int i = l; i < r; ++i)
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
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

int n;
bool ask(int r1, int c1, int r2, int c2) {
  cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
  string res;
  cin >> res;
  return res == "YES";
}

int main() {
  cin >> n;
  int r = 1, c = 1;
  string pre, suf;
  for (int i = 0; i < n - 1; ++i) {
    if (r + 1 <= n && ask(r + 1, c, n, n)) {
      ++r;
      pre += 'D';
    } else {
      ++c;
      pre += 'R';
    }
  }
  r = c = n;
  for (int i = 0; i < n - 1; ++i) {
    if (c - 1 >= 1 && ask(1, 1, r, c - 1)) {
      --c;
      suf += 'R';
    } else {
      --r;
      suf += 'D';
    }
  }
  reverse(all(suf));
  cout << "! " << pre << suf << endl;
  return 0;
}