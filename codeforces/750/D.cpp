#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// rotate anti-clockwise
typedef complex<double> point;
#define EPS 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b)  ((b) - (a))
#define polar(r,t)  ((r) * exp(point(0, (t))))
#define angle(v)  (atan2((v).Y, (v).X))
#define length(v)   ((double)hypot((v).Y, (v).X))
#define lengthSqr(v)  (dot(v, v))
#define dot(a,b)  ((conj(a) * (b)).real())
#define cross(a,b)  ((conj(a) * (b)).imag())
#define rotate(v,t)   (polar(v, t))

const double PI = acos(-1);
const int N = 31;

int t[N];
int n;

void GetOpp(int& dx, int& dy, bool b) {
  complex<double> v(dx, dy);
  if (b) {
    v = rotate(v, PI / 4);
  } else {
    v = rotate(v, -PI / 4);
  }
  dx = round(v.real());
  dy = round(v.imag());
}

set<tuple<int, int, int, int, int>> vis;
set<pair<int, int>> st;

void Dfs(int level, int x, int y, int dx, int dy) {
  if (level == n) return;

  auto curr = make_tuple(level, x, y, dx, dy);
  if (vis.count(curr)) {
    return;
  }

  vis.insert(curr);

  for (int i = 0; i < t[level]; ++i) {

    x += dx;
    y += dy;

    st.insert( { x, y });
  }

  GetOpp(dx, dy, true);
  Dfs(level + 1, x, y, dx, dy);

  GetOpp(dx, dy, false);
  GetOpp(dx, dy, false);
  Dfs(level + 1, x, y, dx, dy);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }

  Dfs(0, 0, 0, -1, 0);

  cout << st.size() << endl;
}
