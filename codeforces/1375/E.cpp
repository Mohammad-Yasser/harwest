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

template <class U, class V>
ostream& operator<<(ostream& os, const pair<U, V>& p) {
  os << p.first << " " << p.second;
  return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

const int N = 1e3 + 5;

vector<int> inv[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;
    v[i].second = i;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (v[i] > v[j]) {
        inv[i].emplace_back(j);
      }
    }
  }

  vector<pair<int, int>> res;
  vector<pair<pair<int, int>, int>> tmp;
  for (int i = 0; i < n; ++i) {
    tmp.clear();
    for (int x : inv[i]) {
      tmp.emplace_back(v[x], x);
    }
    sort(rall(tmp));
    for (auto& t : tmp) {
      res.emplace_back(i + 1, t.second + 1);
      swap(v[i], v[t.second]);
    }
  }
  cout << sz(res) << endl;
  for (auto& p : res) {
    cout << p << endl;
  }

  return 0;
}