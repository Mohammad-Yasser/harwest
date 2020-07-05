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

vector<pair<Long, int>> v(3);

void play(Long y) {
  cout << y << endl;
  int x;
  cin >> x;
  for (auto& p : v) {
    if (p.second == x) {
      p.first += y;
    }
  }
  sort(all(v));
}

int main() {
  //   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  // #ifdef Local
  //   freopen("test.in", "r", stdin);
  // #else
  // #define endl '\n'
  // #endif

  for (int i = 0; i < 3; ++i) {
    cin >> v[i].first;
    v[i].second = i + 1;
  }

  cout << "First" << endl;
  int last = -1;
  play(1e10);
  play(2 * (v[2].first - v[1].first) + v[1].first - v[0].first);
  play(v[2].first - v[1].first);
  return 0;
}