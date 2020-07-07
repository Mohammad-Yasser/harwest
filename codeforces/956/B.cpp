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

const int N = 51;

bool check(const string& a, const string& b) {
  if (a == b) return true;
  for (int i = 0; i < sz(a); ++i) {
    if (a[i] == '#' && b[i] == '#') return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, u;
  cin >> n >> u;
  vector<int> e(n);
  cin >> e;
  Double res = -1;

  for (int i = 0; i + 2 < n; ++i) {
    int j = i + 1;
    int k = upper_bound(begin(e) + j + 1, end(e), u + e[i]) - begin(e) - 1;
    if (k == j) continue;
    res = max(res, 1.0 * (e[k] - e[j]) / (e[k] - e[i]));
  }
  if (res == -1) {
    cout << -1 << endl;
    return 0;
  }
  cout << fixed << setprecision(10) << res << endl;

  return 0;
}