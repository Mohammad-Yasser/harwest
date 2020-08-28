#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define rep(i, a, b) for (int i = a; i < (b); ++i)

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

struct Line {
  mutable Long k, m, p;
  bool operator<(const Line& o) const { return k < o.k; }
  bool operator<(Long x) const { return p < x; }
};

template <bool MAX = true>
struct LineContainer : multiset<Line, less<>> {
  // (for doubles, use inf = 1/.0, div(a,b) = a/b)
  const Long inf = LLONG_MAX;
  Long div(Long a, Long b) {  // floored division
    return a / b - ((a ^ b) < 0 && a % b);
  }
  bool isect(iterator x, iterator y) {
    if (y == end()) {
      x->p = inf;
      return false;
    }
    if (x->k == y->k)
      x->p = x->m > y->m ? inf : -inf;
    else
      x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(Long k, Long m) {
    if (!MAX) k *= -1, m *= -1;
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
  }
  Long query(Long x) {
    assert(!empty());
    auto l = *lower_bound(x);
    auto res = l.k * x + l.m;
    if (!MAX) res *= -1;
    return res;
  }
};

const int P = 100;
const int N = 1e5 + 5;

Long dp[2][N];
Long hill_dist[N];
Long cat_time[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m, p;
  cin >> n >> m >> p;
  for (int i = 2; i <= n; ++i) {
    cin >> hill_dist[i];
    hill_dist[i] += hill_dist[i - 1];
  }
  Long res = 0;
  for (int i = 1; i <= m; ++i) {
    int h, t;
    cin >> h >> t;
    cat_time[i] = t - hill_dist[h];
    res -= cat_time[i];
  }
  sort(cat_time + 1, cat_time + m + 1);

  LineContainer<false> line_container;
  for (int i = 1; i <= p; ++i) {
    line_container.clear();
    bool curr = (i & 1);
    bool prev = !curr;
    for (int j = 0; j <= m; ++j) {
      if (i > 1 || j == 0) line_container.add(-j, dp[prev][j]);
      dp[curr][j] = line_container.query(cat_time[j]) + j * cat_time[j];
    }
  }

  res += dp[p & 1][m];
  cout << res << endl;

  return 0;
}