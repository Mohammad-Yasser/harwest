#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

const int N = 1e5 + 5;

struct Point {
  Long x;
  Long y;

  int ind;

  Point(Long x, Long y) :
    x(x), y(y) {
  }

  Point() {

  }

  friend Long Cross(const Point& p1, const Point& p2) {
    return p1.x * p2.y - p1.y * p2.x;
  }

  Point operator-(const Point& other) const {
    return Point(x - other.x, y - other.y);
  }

};

bool AreClockWise(const Point& p1, const Point& p2, const Point& p3) {
  Point v1 = p2 - p1;
  Point v2 = p3 - p2;

  return Cross(v1, v2) < 0;
}

vector<Point> points;
stack<Point> removed[N];
vector<Point> upper_hull;

void Print() {
  cout << "Hull: \n";
  for (Point& point : upper_hull) {
    cout << point.ind + 1 << ' ';
  }
  cout << "\nEnd hull" << endl;
}

void BuildUpperHull() {
  sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
    return p1.x > p2.x;
  });

  for (Point& p : points) {
    while (upper_hull.size() >= 2) {
      if (AreClockWise(upper_hull[upper_hull.size() - 2], upper_hull.back(),
        p)) {
        removed[p.ind].push(upper_hull.back());
        upper_hull.pop_back();
      } else {
        break;
      }
    }
    upper_hull.push_back(p);
  }
}

int parent[N];

void BuildTree() {
  while (!upper_hull.empty()) {
    Point curr = upper_hull.back();
    upper_hull.pop_back();

    if (upper_hull.empty()) {
      parent[curr.ind] = -2;
    } else {
      parent[curr.ind] = upper_hull.back().ind;
    }

    while (!removed[curr.ind].empty()) {
      upper_hull.push_back(removed[curr.ind].top());
      removed[curr.ind].pop();
    }
  }
}

int n;
// you need to calculate lvl and anc
int lvl[N], anc[N][25];

int GetLevel(int node) {
  if (lvl[node] != 0) return lvl[node];
  if (parent[node] == -2) return lvl[node] = 1;
  return lvl[node] = GetLevel(parent[node]) + 1;
}

void BuildLCA() {
  int lg = ceil(log2(N));
  for (int i = 0; i < n; ++i) {
    anc[i][0] = parent[i];
  }
  for (int j = 1; j < lg; ++j) {
    for (int i = 0; i < n; ++i) {
      if (anc[i][j - 1] < 0) {
        anc[i][j] = -2;
      } else {
        anc[i][j] = anc[anc[i][j - 1]][j - 1];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    GetLevel(i);
  }
}

int LCA(int i, int j) {
  int lg = ceil(log2(N));
  int st = lg;
  if (lvl[i] > lvl[j]) swap(i, j);
  int cur = lvl[j];
  for (; st >= 0; st--)
    if (cur - (1 << st) >= lvl[i]) cur -= (1 << st), j = anc[j][st];
  if (i == j) return i;
  cur = lvl[i];
  for (st = lg; st >= 0; st--)
    if (anc[i][st] != anc[j][st]) cur -= (1 << st), i = anc[i][st], j =
      anc[j][st];
  return anc[i][0];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> n;
  points.resize(n);

  for (int i = 0; i < n; ++i) {
    auto& point = points[i];
    cin >> point.x >> point.y;
    point.ind = i;
  }

  BuildUpperHull();
  BuildTree();
  BuildLCA();

//  for (int i = 3; i < n; ++i) {
//    for (int j = 0; j < 3; ++j) {
//      cout << i + 1 << ' ' << j << ' ' << anc[i][j] + 1 << endl;
//    }
//  }

  int m;
  cin >> m;

  while (m--) {
    int x, y;
    cin >> x >> y;
    --x, --y;

    cout << LCA(x, y) + 1 << ' ';
  }
}
