#include <bits/stdc++.h>

using namespace std;

typedef long long Long;

const int N = 1e3 + 3;

struct Circle {
  int x, y, r;
  Long GetArea() {
    return 1LL * r * r;
  }
} circles[N];

int parent[N];

vector<int> children[N];

Long Dist(int x1, int y1, int x2, int y2) {
  Long dx = x1 - x2;
  Long dy = y1 - y2;
  return dx * dx + dy * dy;
}

bool IsInside(int i, int j) {
  return Dist(circles[i].x, circles[i].y, circles[j].x, circles[j].y)
    <= circles[j].GetArea();
}

Long memo[N][2][2];
bool vis[N][2][2];

bool nxt[N][2][2];

Long Solve(int node, bool first_odd, bool second_odd) {
  Long& res = memo[node][first_odd][second_odd];
  if (vis[node][first_odd][second_odd]) {
    return res;
  }
  vis[node][first_odd][second_odd] = true;

  bool halves[2] = { first_odd, second_odd };

  res = -1e15;

  for (int half = 0; half < 2; ++half) {
    halves[half] ^= 1;
    Long tmp = circles[node].GetArea() * (halves[half] ? 1 : -1);
    for (int child : children[node]) {
      tmp += Solve(child, halves[0], halves[1]);
    }
    halves[half] ^= 1;

    if (tmp > res) {
      res = tmp;
      nxt[node][first_odd][second_odd] = half;
    }

    res = max(res, tmp);
  }

  return res;
}

int n;

void BuildForest() {
  for (int i = 0; i < n; ++i) {
    parent[i] = -1;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (circles[i].r >= circles[j].r) continue;
      if (IsInside(i, j)
        && (parent[i] == -1 || circles[j].r < circles[parent[i]].r)) {
        parent[i] = j;
      }
    }
    children[parent[i]].push_back(i);
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> circles[i].x >> circles[i].y >> circles[i].r;
  }

  BuildForest();

  Long res = 0;

  for (int i = 0; i < n; ++i) {
    if (parent[i] != -1) continue;
    res += Solve(i, false, false);
  }


  cout << fixed << setprecision(10) << res * acos(-1) << '\n';

  return 0;
}
