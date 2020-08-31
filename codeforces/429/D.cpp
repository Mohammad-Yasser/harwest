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

#define square(x) ((x) * (x))

struct Point {
  Long x, y;
  Long dist2(const Point& other) const {
    return square(x - other.x) + square(y - other.y);
  }
  friend ostream& operator<<(ostream& os, const Point& p) {
    return os << p.x << " " << p.y;
  }
};

// Sort by x before calling.
Long getClosestPairOfPoints(int l, int r, vector<Point>& points) {
  if (l == r) return LLONG_MAX;
  int m = (l + r) / 2;
  Long res = min(getClosestPairOfPoints(l, m, points),
                 getClosestPairOfPoints(m + 1, r, points));
  inplace_merge(begin(points) + l, begin(points) + m + 1, begin(points) + r + 1,
                [](const auto& a, const auto& b) { return a.y < b.y; });
  vector<Point> candidates;
  for (int i = l; i <= r; ++i) {
    if (abs(points[i].x - m) <= res) candidates.emplace_back(points[i]);
  }
  for (int i = 0; i < sz(candidates); ++i) {
    int j = i + 1;
    auto& current = candidates[i];
    while (j < sz(candidates) && square(candidates[j].y - current.y) <= res) {
      res = min(res, current.dist2(candidates[j]));
      ++j;
    }
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
  vector<Point> points;
  for (int i = 0; i < n; ++i) {
    int val;
    cin >> val;
    if (i != 0) val += points.back().y;
    points.push_back({i, val});
  }
  sort(all(points), [](const auto& a, const auto& b) { return a.x < b.x; });
  cout << getClosestPairOfPoints(0, n - 1, points) << endl;
  return 0;
}
