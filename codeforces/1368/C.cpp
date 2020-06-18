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
typedef unsigned long long Long;
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

  set<pair<int, int>> st;

  pair<int, int> curr = {0, 0};

  for (int i = 0; i < n; ++i) {
    st.emplace(curr);
    st.emplace(curr.first + 1, curr.second);
    st.emplace(curr.first + 1, curr.second + 1);
    st.emplace(curr.first, curr.second + 1);
    st.emplace(curr.first - 1, curr.second);
    st.emplace(curr.first - 1, curr.second - 1);
    st.emplace(curr.first, curr.second - 1);
    curr = make_pair(curr.first + 1, curr.second + 1);
  }

  cout << st.size() << endl;
  for (auto& x : st) {
    cout << x.first << " " << x.second << endl;
  }

  return 0;
}