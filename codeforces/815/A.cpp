#include <bits/stdc++.h>

using namespace std;

const int MOD = round(1e9 + 7);
typedef long long Long;

const int N = 103;
const int OO = 1e7;

int grid[N][N];
int tmp[N][N];

int rows[N];
int cols[N];

int n, m;

int Solve(int row0) {
  rows[0] = row0;

  int res = 0;

  for (int i = 0; i < m; ++i) {
    cols[i] = grid[0][i] - rows[0];
    if (cols[i] < 0) {
      return OO;
    }
    res += cols[i];
  }

  for (int i = 0; i < n; ++i) {
    rows[i] = grid[i][0] - cols[0];
    if (rows[i] < 0) {
      return OO;
    }
    res += rows[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      tmp[i][j] = rows[i] + cols[j];
      if (tmp[i][j] != grid[i][j]) {
        return OO;
      }
    }
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
    }
  }

  int res = OO;
  int best = -1;
  for (int i = 0; i <= 500; ++i) {
    int tmp = Solve(i);
    if (tmp < res) {
      res = tmp;
      best = i;
    }
  }

  if (res == OO) {
    cout << -1;
    return 0;
  }

  cout << res << '\n';

  rows[0] = best;
  cols[0] = grid[0][0] - best;

  for (int i = 0; i < m; ++i) {
    int tmp = grid[0][i] - rows[0];
    while (tmp--) {
      cout << "col " << i + 1 << '\n';
    }
  }

  for (int i = 0; i < n; ++i) {
    int tmp = grid[i][0] - cols[0];
    while (tmp--) {
      cout << "row " << i + 1 << '\n';
    }
  }

  return 0;
}
