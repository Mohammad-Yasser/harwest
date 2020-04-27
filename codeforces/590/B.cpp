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
typedef Point Vector;
const Point Origin(0, 0);

Double dot(Point p, Point q) { return p.x * q.x + p.y * q.y; }

Point dest;
Point v, w;
Double t;
Double v_max;

void read() {
  Double x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  dest.x = x2 - x1;
  dest.y = y2 - y1;
  cin >> v_max >> t;
  cin >> v.x >> v.y >> w.x >> w.y;
}

bool valid(Double ans) {
  Point d = v * min(t, ans) + w * max(Double(0), ans - t) - dest;
  return d.length() <= v_max * ans;
}

Double solve() {
  Double low = 0, high = 1e30;

  for (int i = 0; i < 200; ++i) {
    Double mid = (low + high) / 2;
    if (valid(mid)) {
      high = mid;
    } else {
      low = mid;
    }
  }

  return (low + high) / 2;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  read();
  cout << fixed << setprecision(10) << solve() << endl;
  return 0;
}
