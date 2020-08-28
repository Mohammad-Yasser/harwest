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

bool isZero(Long x) { return x == 0; }

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

// Add pairs (m, c) then query(x) returns min {m * x + c}.
// Complexity: O(number of insertions + number of queries).
// Maintains the lower convex hull.
// Lines added must be sorted non-decreasingly by slope.
// Queries must be sorted non-increasingly by x.
struct LinearLineContainer {
  deque<P>
      lines;  // Each line is represented as a 2D point (slope, y-intercept).
  void add(Long m, Long c) {
    P line(m, c);
    while (sz(lines) >= 2 &&
           lines[sz(lines) - 2].cross(lines[sz(lines) - 1], line) <= 0) {
      lines.pop_back();
    }
    if (!lines.empty() && lines.back().x == line.x) {
      lines.back().y = min(lines.back().y, line.y);
    } else {
      lines.emplace_back(line);
    }
  }

  Long query(Long x) {
    P p(x, 1);
    while (sz(lines) > 1 && lines[1].dot(p) <= lines[0].dot(p)) {
      lines.pop_front();
    }
    return lines[0].dot(p);
  }
};

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

  LinearLineContainer line_container;
  for (int i = 1; i <= p; ++i) {
    line_container.lines.clear();
    bool curr = (i & 1);
    bool prev = !curr;
    for (int j = 0; j <= m; ++j) {
      if (i > 1 || j == 0) line_container.add(j, dp[prev][j]);
      dp[curr][j] = line_container.query(-cat_time[j]) + j * cat_time[j];
    }
  }

  res += dp[p & 1][m];
  cout << res << endl;

  return 0;
}