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

const int N = 23;
struct DSU {
  int parent[N];
  int sz[N];
  void init() {
    for (int i = 0; i < N; ++i) {
      parent[i] = i;
      sz[i] = 1;
    }
  }
  int getRoot(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
  }
  void join(int x, int y) {
    x = getRoot(x);
    y = getRoot(y);
    if (x == y) return;
    parent[x] = y;
    sz[y] += sz[x];
  }
} dsu;

int solve(const string& a, const string& b) {
  dsu.init();
  for (int i = 0; i < sz(a); ++i) {
    if (a[i] > b[i]) return -1;
    if (a[i] < b[i]) {
      dsu.join(a[i], b[i]);
    }
  }
  int res = 0;
  for (int i = 0; i < N; ++i) {
    if (dsu.parent[i] == i) {
      res += dsu.sz[i] - 1;
    }
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < n; ++i) {
      a[i] -= 'a';
      b[i] -= 'a';
    }
    cout << solve(a, b) << endl;
  }

  return 0;
}