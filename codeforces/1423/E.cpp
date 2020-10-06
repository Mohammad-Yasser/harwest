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
#define rep(i, l, r) for (int i = l; i < r; ++i)
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
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

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
bool isZero(Long x) { return x == 0; }

int compareDoubles(Double x, Double y, Double eps = EPS) {
  if (areEqual(x, y, eps)) return Relation::EQUAL;
  if (x < y) return Relation::LESS_THAN;
  return Relation::GREATER_THAN;
}

template <typename T = Double>
struct Point {
  typedef Point P;
  const static P Invalid;
  const static P Origin;

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
  T dist2(const P& p) const { return getVector(p).dist2(); }
  T dist2() const { return (*this).dot(*this); }
  Double dist(const P& p) const { return sqrt(dist2(p)); }
  Double dist() const { return sqrt(dist2()); }
  P rotateCCW90() const { return P(-y, x); }
  P rotateCCW90Around(const P& p) const {
    return p + p.getVector(*this).rotateCCW90();
  }
  // Scales the plane by 1/cos(45 degrees)
  P rotateCCW45WithScale() const { return P(x - y, x + y); }
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

  // Project point c onto line segment through a and b (assuming a != b).
  P projectOnSegment(const P& a, const P& b) const {
    P& c = *this;
    P ab = a.getVector(b);
    P ac = a.getVector(c);

    Double r = dot(ac, ab), d = a.dist2(b);
    if (r < 0) return a;
    if (r > d) return b;

    return a + ab * r / d;
  }

  P reflectAroundLine(const P& a, const P& b) const {
    return projectOnLine(a, b) * 2 - (*this);
  }

  friend istream& operator>>(istream& is, P& p) {
    static string x, y;
    is >> x >> y;
    p.x = stod(x), p.y = stod(y);
    return is;
  }

  friend ostream& operator<<(ostream& os, const P& p) {
    return os << p.x << " " << p.y;
  }
};

template <typename T>
const Point<T> Point<T>::Invalid = Point<T>(numeric_limits<T>::max(),
                                            numeric_limits<T>::max());
template <typename T>
const Point<T> Point<T>::Origin = Point<T>(0, 0);

typedef Point<Double> Vector;
typedef Point<Double> P;

template <class P>
bool inPolygon(const vector<P>& p, const P& a) {
  int cnt = 0, n = sz(p);
  rep(i, 0, n - 1) {
    P q = p[i + 1];
    // if (onSegment(p[i], q, a)) return !strict;
    // or: if (segDist(p[i], q, a) <= eps) return !strict;
    cnt ^= ((a.y < p[i].y) - (a.y < q.y)) * a.cross(p[i], q) > 0;
  }
  return cnt;
}

template <class T>
T polygonArea2(const vector<Point<T>>& v) {
  T a = v.back().cross(v[0]);
  rep(i, 0, sz(v) - 1) a += v[i].cross(v[i + 1]);
  return a;
}

using Polygon = vector<P>;

struct Circle {
  Double r;
  P center;
};

Double segDist(const P& s, const P& e, const P& p) {
  if (s == e) return (p - s).dist();
  auto d = (e - s).dist2(), t = min(d, max(Double(.0), (p - s).dot(e - s)));
  return ((p - s) * d - (e - s) * t).dist() / d;
}

Double pointPolygonDistance(const P& point, const Polygon& polygon) {
  if (inPolygon(polygon, point)) return 0;
  Double res = 1e15;
  for (int i = 0; i + 1 < sz(polygon); ++i) {
    res = min(res, segDist(polygon[i], polygon[i + 1], point));
  }
  return res;
}

bool circleIntersectsPolygon(const Circle& circle, const Polygon& polygon) {
  return compareDoubles(pointPolygonDistance(circle.center, polygon),
                        circle.r) != Relation::GREATER_THAN;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  Double tmp;

  cin >> tmp >> tmp >> n;
  vector<Polygon> polys(n);
  vector<Double> areas;
  areas.reserve(n);
  for (auto& poly : polys) {
    int v;
    cin >> v;
    poly.resize(v);
    cin >> poly;
    areas.emplace_back(polygonArea2(poly));
    poly.emplace_back(poly[0]);
  }
  cout << fixed << setprecision(4);
  int q;
  cin >> q;
  while (q--) {
    Circle circle;
    cin >> circle.center >> circle.r;
    vector<int> res;
    Double sum_areas = 0;
    for (int i = 0; i < n; ++i) {
      if (circleIntersectsPolygon(circle, polys[i])) {
        sum_areas += areas[i];
        res.emplace_back(i);
      }
    }
    cout << sum_areas / 2 << " " << sz(res) << " " << res << endl;
  }

  return 0;
}