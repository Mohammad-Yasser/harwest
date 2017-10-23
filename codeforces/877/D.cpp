#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 1e3 + 5;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

string grid[N];

int n, m, k;

struct Point {
  int x, y;
  Point() {
  }
  Point(int x, int y) :
    x(x), y(y) {
  }
  bool operator ==(const Point& other) const {
    return x == other.x && y == other.y;
  }
};

Point start, goal;

bool vis[N][N];
int inQ[N][N];

bool valid(const Point& p) {
  if (min(p.x, p.y) < 1 or p.x > n or p.y > m or vis[p.x][p.y]) return false;
  return grid[p.x][p.y] != '#';
}

int bfs() {
  queue<Point> q;
  int level = 0;

  q.push(start);

  memset(inQ , 0x3f , sizeof inQ);

  while (!q.empty()) {
    int sz = q.size();
    while (sz--) {
      Point curr = q.front();
      q.pop();
      if (vis[curr.x][curr.y]) continue;
      vis[curr.x][curr.y] = true;

      if (curr == goal) return level;

      for (int dir = 0; dir < 4; ++dir) {
        for (int i = 1; i <= k; ++i) {
          Point nxt(curr.x + i * dx[dir], curr.y + i * dy[dir]);
          if (!valid(nxt)) break;
          if (inQ[nxt.x][nxt.y] < level) break;
          if (inQ[nxt.x][nxt.y] == level) continue;
          q.push(nxt);
          inQ[nxt.x][nxt.y] = level;
        }
      }
    }
    ++level;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> n >> m >> k;

  for (int i = 1; i <= n; ++i) {
    cin >> grid[i];
    grid[i] = " " + grid[i];
  }

  cin >> start.x >> start.y >> goal.x >> goal.y;

  swap(start, goal);
  cout << bfs();

}
