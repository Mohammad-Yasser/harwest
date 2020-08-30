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

int last[2];
set<pair<int, int>> st;

bool solve() {
  bool T = false;
  last[0] = last[1] = 0;
  while (true) {
    T ^= 1;
    if (st.empty()) return !T;
    auto mx = st.end();
    --mx;
    if (last[!T] == mx->second) {
      if (sz(st) == 1) return !T;
      --mx;
    }
    auto tmp = *mx;
    --tmp.first;
    st.erase(mx);
    if (tmp.first > 0) st.emplace(tmp);
    last[T] = tmp.second;
  }
  assert(false);
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  // freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif
  int t;
  cin >> t;

  while (t--) {
    st.clear();
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      st.emplace(x, i);
    }
    cout << (solve() ? "T" : "HL") << endl;
  }
  return 0;
}