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
    return x == p.x && y == p.y;
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
  P rotateCCW90Around(const P& p) const {
    return p + p.getVector(*this).rotateCCW90();
  }
  P rotateCCW(Double angle) const {
    return Point(x * cos(angle) - y * sin(angle),
                 x * sin(angle) + y * cos(angle));
  }

  // Project point onto line through a and b (assuming a != b).
  P projectOnLine(const P& a, const P& b) const {
    P ab = a.getVector(b);
    P ac = a.getVector(*this);
    return a + ab * ac.dot(ab) / a.dist2(b);
  }

  P reflectAroundLine(const P& a, const P& b) const {
    return projectOnLine(a, b) * 2 - (*this);
  }

  friend bool LinesParallel(const P& a, const P& b, const P& c, const P& d) {
    return isZero((b - a).cross(c - d));
  }

  friend bool areCollinear(const P& a, const P& b, const P& c) {
    return LinesParallel(a, b, b, c);
  }
};

typedef Point<Long> P;
vector<P> convexHull(vector<P> pts) {
  if (sz(pts) <= 1) return pts;
  sort(all(pts));
  vector<P> h(2 * sz(pts) + 1);
  int s = 0, t = 0;
  for (int it = 2; it--; s = --t, reverse(all(pts)))
    for (P p : pts) {
      while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) < 0) t--;
      h[t++] = p;
    }
  return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
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

  vector<P> a(n);
  vector<P> b;

  for (auto& p : a) {
    cin >> p.x >> p.y;
    b.emplace_back(p);
  }

  int m;
  cin >> m;

  while (m--) {
    int x, y;
    cin >> x >> y;
    b.emplace_back(x, y);
  }

  b = convexHull(b);
  a = convexHull(a);

  cout << (a == b ? "YES" : "NO") << endl;

  return 0;
}