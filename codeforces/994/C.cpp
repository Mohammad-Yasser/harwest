#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
typedef long long Long;

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

using Double = long double;

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

  friend istream& operator>>(istream& is, P& p) { return is >> p.x >> p.y; }

  friend ostream& operator<<(ostream& os, P& p) {
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

bool inRange(int x, int l, int r) { return min(l, r) <= x && x <= max(l, r); }

struct Square {
  P a, b;
  Square(const vector<P>& v) {
    a.x = a.y = LLONG_MAX;
    b.x = b.y = LLONG_MIN;
    for (auto& p : v) {
      a.x = min(a.x, p.x);
      a.y = min(a.y, p.y);
      b.x = max(b.x, p.x);
      b.y = max(b.y, p.y);
    }
  }
  P center() const { return (a + b) / 2; }
  bool contains(const P& p) {
    return inRange(p.x, a.x, b.x) && inRange(p.y, a.y, b.y);
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  vector<P> v1(4), v2(4);
  cin >> v1 >> v2;
  auto rotated_v2 = v2;
  for (auto& p : rotated_v2) {
    p = p.rotateCCW45WithScale();
  }
  Square sq1(v1), sq2(v2), rotated_sq2(rotated_v2);
  v1.emplace_back(sq1.center());
  v2.emplace_back(sq2.center());
  for (auto& p : v1) {
    if (rotated_sq2.contains(p.rotateCCW45WithScale())) {
      cout << "YES" << endl;
      return 0;
    }
  }
  for (auto& p : v2) {
    if (sq1.contains(p)) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
