#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef unsigned long long Long;

typedef double Double;
typedef complex<Double> Point;
// rotate anti-clockwise
#define EPS 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b)  ((b) - (a))
#define polar(r,t)  ((r) * exp(Point(0, (t))))
#define angle(v)  (atan2((v).Y, (v).X))
#define length(v)   ((Double)hypot((v).Y, (v).X))
#define lengthSqr(v)  (dot(v, v))
#define dot(a,b)  ((conj(a) * (b)).real())
#define cross(a,b)  ((conj(a) * (b)).imag())
#define rotate(v,t)   (polar(v, t))
#define rotateabout(v,t,a)  (rotate(vec(a, v), t) + (a))
#define reflect(p,m)  ((conj((p) / (m))) * (m))
#define normalize(p)  ((p) / length(p))
#define same(a,b)   (length(vec(a, b)) < EPS)
#define mid(a,b)  (((a) + (b)) / Point(2, 0))
#define perp(a)   (Point(-(a).Y, (a).X))
#define collinear   PointOnLine
enum STATE {
  IN, OUT, BOUNDRY
};

double PointLineDist(const Point& a, const Point& b, const Point& p) {
  // handle degenrate case: (a,b) is Point
  return fabs(cross(vec(a,b),vec(a,p)) / length(vec(a,b)));
}

const int N = 1e3 + 5;

Point points[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    points[i] = Point(x, y);
  }

  double res = 1e40;

  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n, k = (j + 1) % n;
    res = min(res, PointLineDist(points[i], points[k], points[j]));
  }

  cout << fixed << setprecision(10) << res / 2;

}

