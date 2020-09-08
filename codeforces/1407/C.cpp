#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse4,sse4.2,popcnt,abm,mmx,avx")
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

const int RANDOM =
    chrono::high_resolution_clock::now().time_since_epoch().count();

int query(int i, int j) {
  cout << "? " << i << " " << j << endl;
  int res;
  cin >> res;
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> res(n + 1);
  int mx = 1;
  for (int i = 2; i <= n; ++i) {
    int i_mod_mx = query(i, mx);
    int mx_mod_i = query(mx, i);
    if (i_mod_mx > mx_mod_i) {
      res[i] = i_mod_mx;
    } else {
      res[mx] = mx_mod_i;
      mx = i;
    }
  }
  res[mx] = n;
  res.erase(begin(res));
  cout << "! " << res << endl;

  return 0;
}