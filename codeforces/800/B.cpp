#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

typedef complex<double> Point;
// rotate anti-clockwise
#define EPS 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b)  ((b) - (a))
#define polar(r,t)  ((r) * exp(Point(0, (t))))
#define angle(v)  (atan2((v).Y, (v).X))
#define length(v)   ((double)hypot((v).Y, (v).X))
#define lengthSqr(v)  (dot(v, v))
#define dot(a,b)  ((conj(a) * (b)).real())
#define cross(a,b)  ((conj(a) * (b)).imag())
#define rotate(v,t)   (polar(v, t))
#define rotateabout(v,t,a)  (rotate(vec(a, v), t) + (a))
#define reflect(p,m)  ((conj((p) / (m))) * (m))
#define normalize(p)  ((p) / length(p))
#define same(a,b)   (lengthSqr(vec(a, b)) < EPS)
#define mid(a,b)  (((a) + (b)) / Point(2, 0))
#define perp(a)   (Point(-(a).Y, (a).X))
#define collinear   PointOnLine

const int N = 3e3 + 3;
Point points[N];

double pointLineDist(const Point& a, const Point& b, const Point& p) {
  // handle degenrate case: (a,b) is point
  return fabs(cross(vec(a,b),vec(a,p)) / length(vec(a,b)));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    points[i] = Point(x, y);
  }

  for (int i = n; i < 2 * n; ++i) {
    points[i] = points[i % n];
  }

  double res = 1e15;

  for (int i = 1; i <= n; ++i) {
    res = min(res, pointLineDist(points[i - 1], points[i + 1], points[i]));
  }

  cout << fixed << setprecision(6) << res / 2;

  return 0;
}
