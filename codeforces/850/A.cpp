#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 1e3 + 3;

struct Point {
  int x[5];

  int operator*(const Point& other) const {
    int res = 0;
    for (int i = 0; i < 5; ++i) {
      res += x[i] * other.x[i];
    }
    return res;
  }
  Point operator-(const Point& other) const {
    Point res;
    for (int i = 0; i < 5; ++i) {
      res.x[i] = x[i] - other.x[i];
    }
    return res;
  }
};

int n;

vector<Point> points;

vector<Point> getVectors(int ind) {
  vector<Point> v;
  for (int i = 0; i < n; ++i) {
    if (i == ind) continue;
    v.push_back(points[i] - points[ind]);
  }
  return v;
}

bool check(int ind) {
  vector<Point> v = getVectors(ind);
  if (v.empty()) return true;
  int trials = 1e4;
  while (trials--) {
    int r1 = rand() % v.size();
    int r2 = rand() % v.size();
    if (r1 == r2) continue;
    if (v[r1] * v[r2] > 0) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  srand(time(0));

  cin >> n;
  points.resize(n);
  for (int i = 0; i < n; ++i) {
    for (int& j : points[i].x) {
      cin >> j;
    }
  }

  vector<int> good;
  for (int i = 0; i < n; ++i) {
    if (check(i)) {
      good.push_back(i + 1);
    }
  }

  cout << good.size() << '\n';
  for (int x : good) {
    cout << x << '\n';
  }

}
