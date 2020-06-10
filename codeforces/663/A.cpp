#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
typedef long long Long;
typedef long double Double;

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

const int N = 1e5 + 5;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  vector<int> v;
  int n;
  char c;
  int sign = 1;
  while (cin >> c) {
    if (c == '=') {
      cin >> n;
      break;
    }
    if (c == '?') {
      v.emplace_back(sign);
    }
    if (c == '+') {
      sign = 1;
    }
    if (c == '-') {
      sign = -1;
    }
  }

  int sum = accumulate(all(v), 0);

  for (int& x : v) {
    while (abs(x) < n && sum != n && ((sum < n) == (x > 0))) {
      sum += x / abs(x);
      x += x / abs(x);
    }
  }

  if (sum != n) {
    cout << "Impossible" << endl;
    return 0;
  }

  cout << "Possible" << endl;
  cout << v[0];
  for (int i = 1; i < sz(v); ++i) {
    if (v[i] > 0) {
      cout << " + ";
    } else {
      cout << " - ";
    }
    cout << abs(v[i]);
  }

  cout << " = " << n << endl;

  return 0;
}