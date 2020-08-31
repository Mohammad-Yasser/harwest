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

bool isZero(Long x) { return x == 0; }

template <typename T>
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
  // Scales the plane by 1/cos(45 degrees)
  P rotateCCW45WithScale() const { return P(x - y, x + y); }
  P rotateCCW90Around(const P& p) const {
    return p + p.getVector(*this).rotateCCW90();
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

typedef Point<Long> P;

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
  for (auto& p : v2) {
    p = p.rotateCCW45WithScale();
  }
  Square sq1(v1), sq2(v2);
  for (int i = -100; i <= 100; ++i) {
    for (int j = -100; j <= 100; ++j) {
      P p(i, j);
      P rotated = p.rotateCCW45WithScale();
      if (sq1.contains(p) && sq2.contains(rotated)) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
