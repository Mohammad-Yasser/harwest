#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
 Let the points be a, b, c, d.
 If a isn't connected to d:
 d = a + b - a + c - a = b + c - a.
 If a isn't connected to c:
 c = b + d - a.
 d = c + a - b.
 If a isn't connected to b:
 b = c + d - a.
 d = b + a - c.
 */

typedef complex<int> Point;

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("test.in", "rt", stdin);
//  freopen("o.txt", "wt", stdout);
#endif

  Point points[3];
  Point sum(0, 0);
  for (int i = 0; i < 3; ++i) {
    int x, y;
    cin >> x >> y;
    points[i] = Point(x, y);
    sum += points[i];
  }

  vector<Point> sol;

  for (int i = 0; i < 3; ++i) {
    Point d = sum - 2 * points[i];
    if (find(points, points + 3, d) != points + 3) continue;
    sol.push_back(d);
  }
  cout << sol.size() << '\n';
  for (auto &d : sol) {
    cout << d.real() << ' ' << d.imag() << '\n';
  }

  return 0;
}

