#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
typedef long long Long;

const int N = 1e5 + 5;

typedef long double Double;

const Double EPS = 1e-10;

enum Relation { LESS_THAN, EQUAL, GREATER_THAN };

bool areEqual(Double x, Double y, Double eps = EPS) {
  auto diff = abs(x - y);
  x = abs(x), y = abs(y);
  if (diff <= eps) return true;
  if (min(x, y) <= eps) return false;
  return diff <= eps * max(x, y);
}

bool isZero(Double x, Double eps = EPS) { return abs(x) <= eps; }

int compareDoubles(Double x, Double y, Double eps = EPS) {
  if (areEqual(x, y, eps)) return Relation::EQUAL;
  if (x < y) return Relation::LESS_THAN;
  return Relation::GREATER_THAN;
}

template <class T>
struct Point {
  typedef Point P;
  T x = 0, y = 0;
  Point(T x, T y) : x(x), y(y) {}
  Point() {}
  pair<T, T> to_pair() const { return make_pair(x, y); }
  Point operator+(const Point& p) const { return Point{x + p.x, y + p.y}; }
  Point operator-(const Point& p) const { return Point{x - p.x, y - p.y}; }
  Point operator*(T c) const { return Point(x * c, y * c); }
  Point operator/(T c) const { return Point(x / c, y / c); }
  bool operator<(const Point& p) const {
    return (*this) != p && to_pair() < p.to_pair();
  }
  bool operator>(const Point& p) const { return (*this) != p && !(*this < p); }
  bool operator==(const Point& p) const {
    return isZero(this->x - p.x) && isZero(this->y - p.y);
  }
  bool operator!=(const Point& p) const { return !(*this == p); }
  T cross(const P& p) const { return x * p.y - y * p.x; }
  T cross(const P& a, const P& b) const { return (a - *this).cross(b - *this); }
  T dot(const P& p) const { return x * p.x + y * p.y; }
  P midPoint(const P& p) const { return ((*this) + p) / 2; }
  P getVector(const P& p) const { return p - (*this); }
  T dist2(const P& p) const { return getVector(p).length2(); }
  T length2() const { return (*this).dot(*this); }
  Double dist(const P& p) const { return sqrt(dist2(p)); }
  P rotateCCW90() const { return P(-y, x); }
};

template <class T>
istream& operator>>(istream& is, Point<T>& p) {
  return is >> p.x >> p.y;
}

template <class T>
ostream& operator<<(ostream& os, Point<T>& p) {
  return os << p.x << " " << p.y;
}

Double dist[N];

typedef Point<Double> P;

P bin;
P bottles[N];
P a, b;
Double suff[N];
Double pre[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> a >> b >> bin;

  int n;
  cin >> n;

  Double res = 1e30;
  Double total = 0;
  for (int i = 0; i < n; ++i) {
    cin >> bottles[i];
    dist[i] = 2 * bin.dist(bottles[i]);
    total += dist[i];
  }

  for (int s2 = 0; s2 < 2; ++s2) {
    for (int s = 0; s < 2; ++s) {
      for (int i = 0; i < n; ++i) {
        pre[i] = a.dist(bottles[i]) + bin.dist(bottles[i]) - dist[i];
        if (i > 0) {
          pre[i] = min(pre[i], pre[i - 1]);
        }
      }
      for (int i = n - 1; i >= 0; --i) {
        suff[i] = b.dist(bottles[i]) + bin.dist(bottles[i]) - dist[i];
        if (i < n - 1) {
          suff[i] = min(suff[i], suff[i + 1]);
        }
      }
      for (int i = 0; i < n; ++i) {
        if (i + 1 < n) res = min(res, total + pre[i] + suff[i + 1]);
        res = min(res, total + pre[i]);
      }
      swap(a, b);
    }
    reverse(bottles, bottles + n);
    reverse(dist, dist + n);
  }

  cout << fixed << setprecision(10) << res << endl;

  return 0;
}