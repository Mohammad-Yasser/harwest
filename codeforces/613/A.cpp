#include <bits/stdc++.h> 
using namespace std;
typedef complex<double> point;
#define EPS 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b) 	((b) - (a))
#define polar(r,t) 	((r) * exp(point(0, (t))))
#define angle(v) 	(atan2((v).Y, (v).X))
#define length(v) 	((double)hypot((v).Y, (v).X))
#define lengthSqr(v) 	(dot(v, v))
#define dot(a,b) 	((conj(a) * (b)).real())
#define cross(a,b) 	((conj(a) * (b)).imag())
#define rotate(v,t) 	(polar(v, t))
#define rotateabout(v,t,a)  (rotate(vec(a, v), t) + (a))
#define reflect(p,m) 	((conj((p) / (m))) * (m))
#define normalize(p) 	((p) / length(p))
#define same(a,b) 	(lengthSqr(vec(a, b)) < EPS)
#define mid(a,b)	(((a) + (b)) / point(2, 0))
#define perp(a) 	(point(-(a).Y, (a).X))
#define colliner 	pointOnLine
enum STATE {
	IN, OUT, BOUNDRY
};
point polygon[100005];
point centre;
int n;

double pointLineDist(const point& a, const point& b, const point& p) {
// handle degenrate case: (a,b) is point
	return fabs(cross(vec(a,b),vec(a,p)) / length(vec(a,b)));
}

double pointSegmentDist(const point &a, const point &b, const point &p) {
	if (dot(vec(a,b),vec(a,p)) < EPS)
	  return length(vec(a,p));
	if (dot(vec(b,a),vec(b,p)) < EPS)
	  return length(vec(b,p));
	return pointLineDist(a, b, p);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif

	cin >> n;
	int x, y;
	cin >> x >> y;
	centre = point(x, y);

	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		polygon[i] = point(x, y);
	}
	polygon[n] = polygon[0];
	double r2 = 0, r1 = 1e7;
	for (int i = 0; i < n; ++i) {
		r2 = max(r2, hypot(polygon[i].X - centre.X, polygon[i].Y - centre.Y));
		r1 = min(r1, pointSegmentDist(polygon[i], polygon[i + 1], centre));
	}
	cout << fixed << setprecision(6) << acos(-1) * (r2 * r2 - r1 * r1);

}
