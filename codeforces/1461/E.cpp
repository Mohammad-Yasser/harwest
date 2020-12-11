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

const int N = 1e6 + 5;
bool vis[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  Long k, l, r, t, x, y;
  cin >> k >> l >> r >> t >> x >> y;
  if (y < x) {
    if (k + y <= r) k += y;
    if (k - x < l) {
      cout << "No" << endl;
      return 0;
    }
    k -= x;
    --t;
    if ((k - l) / (x - y) >= t) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
    return 0;
  }
  while (true) {
    Long days = (k - l) / x;
    t -= days;
    k -= days * x;
    if (t <= 0 || vis[k - l]) {
      cout << "Yes" << endl;
      return 0;
    }
    vis[k - l] = true;
    if (k + y > r) {
      cout << "No" << endl;
      return 0;
    }
    k += y;
  }

  return 0;
}
