#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 5e3 + 5;

string grid[N];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

vector<pair<int, int>> to[N][4];

int n, m;

pair<int, int> getNextCell(int i, int dir, int j) {
  int to_i = i + dx[dir];
  int to_j = j + dy[dir];

  if (to_i < 0 || to_i == n || to_j < 0 || to_j == m) {
    return {-1, -1};
  }
  return {to_i , to_j};
}

void initNxt() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j) {
      to[i][j].resize(m);
    }
    for (int j = 0; j < m; ++j) {
      for (int dir = 0; dir < 4; ++dir) {
        if (isalpha(grid[i][j])) {
          to[i][dir][j] = {i,j};
        } else {
          to[i][dir][j] = getNextCell(i , dir , j);
        }
      }
    }
  }
}

pair<int, int> getTo(int i, int dir, int j) {
  if (to[i][dir][j] == make_pair(i, j)) {
    return make_pair(i, j);
  }
  if (to[i][dir][j] == make_pair(-1, -1)) {
    return make_pair(-1, -1);
  }
  return to[i][dir][j] = getTo(to[i][dir][j].first, dir, to[i][dir][j].second);
}

string dirs = "DURL";

int solve(int i, int j) {
  initNxt();
  int res = 0;
  while (i != -1 && j != -1) {
    ++res;
    for (int dir = 0; dir < 4; ++dir) {
      to[i][dir][j] = getNextCell(i, dir, j);
    }

    int dir = dirs.find(grid[i][j]);
    tie(i, j) = getTo(i , dir , j);
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

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    grid[i].resize(m);
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
    }
  }

  int mx = -1, cnt = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '.') continue;
      int tmp = solve(i, j);
      if (tmp > mx) {
        mx = tmp;
        cnt = 0;
      }
      if (tmp == mx) {
        ++cnt;
      }
    }
  }

  cout << mx << " " << cnt << endl;
}
