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

struct Point {
  Double x = 0, y = 0;
  Point(Double x, Double y) : x(x), y(y) {}
  Point() {}
  pair<Double, Double> to_pair() const { return make_pair(x, y); }

  Point getUnit() const { return (*this) / length(); }

  Double length() const { return sqrt(x * x + y * y); }

  void Print() const { cout << x << ", " << y << endl; }
  Point operator+(const Point &p) const { return Point{x + p.x, y + p.y}; }
  Point operator-(const Point &p) const { return Point{x - p.x, y - p.y}; }
  Point operator*(Double c) const { return Point(x * c, y * c); }
  Point operator/(Double c) const { return Point(x / c, y / c); }
  bool operator<(const Point &p) const { return to_pair() < p.to_pair(); }
  bool operator>(const Point &p) const { return !(*this < p); }
  bool operator==(const Point &p) const { return !(*this < p) && !(*this > p); }
  bool operator!=(const Point &p) const { return !(*this == p); }
};

Double cross(Point p, Point q) { return p.x * q.y - p.y * q.x; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  Point a, b, c;
  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

  Point x = (b - a).getUnit();
  Point y = (c - b).getUnit();

  if (isZero((x - y).length())) {
    cout << "TOWARDS" << endl;
    return 0;
  }

  if (cross(x, y) < 0) {
    cout << "RIGHT" << endl;
    return 0;
  }
  cout << "LEFT" << endl;

  return 0;
}
