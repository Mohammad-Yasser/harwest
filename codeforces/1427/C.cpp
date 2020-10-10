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

struct Celeb {
  int t, x, y;
  int best = 0;
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int r, n;
  cin >> r >> n;
  vector<Celeb> v(n);
  for (auto& c : v) {
    cin >> c.t >> c.x >> c.y;
  }
  Celeb start;
  start.t = 0, start.x = 1, start.y = 1;
  v.emplace(v.begin(), start);
  ++n;
  int mx2 = 0;
  int j = n - 1;
  for (int i = n - 1; i >= 0; --i) {
    while (v[j].t - v[i].t > 2 * r) {
      mx2 = max(mx2, v[j].best);
      --j;
    }
    v[i].best = 1 + mx2;
    for (int k = i + 1; k <= j; ++k) {
      if (v[i].t + abs(v[i].x - v[k].x) + abs(v[i].y - v[k].y) <= v[k].t) {
        v[i].best = max(v[i].best, 1 + v[k].best);
      }
    }
  }
  cout << v[0].best - 1 << endl;
  return 0;
}