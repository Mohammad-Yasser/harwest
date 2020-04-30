#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
typedef vector<int> vi;

const int N = 2e5 + 5;

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

  // Project point c onto line segment through a and b (assuming a != b).
  P projectOnSegment(const P& a, const P& b) const {
    P ab = a.getVector(b);
    P ac = a.getVector(*this);

    Double r = dot(ac, ab), d = a.dist2(b);
    if (r < 0) return a;
    if (r > d) return b;

    return a + ab * r / d;
  }

  P reflectAroundLine(const P& a, const P& b) const {
    return projectOnLine(a, b) * 2 - (*this);
  }
};

template <class T>
istream& operator>>(istream& is, Point<T>& p) {
  return is >> p.x >> p.y;
}

template <class T>
ostream& operator<<(ostream& os, Point<T>& p) {
  return os << p.x << " " << p.y;
}

typedef Point<Long> P;

P moles[4];
P homes[4];
P rotations[4][4];

bool isCCWSquare(const vector<P>& points) {
  for (int i = 0; i < 4; ++i) {
    int before = (i + 3) % 4;
    int after = (i + 1) % 4;
    int curr = i;
    if (points[after].rotateCCW90Around(points[curr]) != points[before])
      return false;
  }
  return true;
}

// Returns false if degenerate.
// Doesn't do multiplication, so can work with long long.
bool isSquare(vector<P> points) {
  if (points[0] == points[1] || points[0] == points[2] ||
      points[0] == points[3])
    return false;  // Degenerate

  for (int i = 0; i < 3; ++i) {
    if (isCCWSquare(points)) return true;
    swap(points[2], points[3]);
    if (isCCWSquare(points)) return true;
    swap(points[1], points[2]);
  }
  return false;
}

int bt(int ind, vector<P>& points, int cost) {
  if (ind == 4) {
    if (isSquare(points)) return cost;
    return INT_MAX;
  }
  int res = INT_MAX;
  for (int i = 0; i < 4; ++i) {
    points.emplace_back(rotations[ind][i]);
    res = min(res, bt(ind + 1, points, cost));
    points.pop_back();
    ++cost;
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

  int n;
  cin >> n;

  while (n--) {
    for (int i = 0; i < 4; ++i) {
      cin >> moles[i] >> homes[i];
      rotations[i][0] = moles[i];
      for (int j = 1; j < 4; ++j) {
        rotations[i][j] = rotations[i][j - 1].rotateCCW90Around(homes[i]);
      }
    }
    vector<P> points;
    int res = bt(0, points, 0);
    if (res == INT_MAX) {
      res = -1;
    }
    cout << res << endl;
  }

  return 0;
}
