#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1003;
const int D = 8;
const int MOD = 1000000007;

int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[] = { 1, 0, -1, 1, -1, 1, 0, -1 };

char grid[N][N];
int first_zero[D][N][N];
double sum[D][N][N];

int n;

inline bool IsValid(int i, int j) {
  return min(i, j) >= 0 && max(i, j) < n;
}

inline bool IsRotated(int dx, int dy) {
  return min(abs(dx), abs(dy)) != 0;
}

void GetMaxVal(int i, int j, int rot, double& lg, int& k) {
  k = n;
  for (int d = 0; d < D; ++d) {
    if (rot != IsRotated(dx[d], dy[d])) continue;
    k = min(k, first_zero[d][i][j]);
  }
  lg = log2(grid[i][j]);

  for (int d = 0; d < D; ++d) {
    if (rot != IsRotated(dx[d], dy[d])) continue;
    lg += sum[d][i + k * dx[d]][j + k * dy[d]] - sum[d][i][j];
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[i][j];
      grid[i][j] -= '0';
    }
  }

  for (int d = 0; d < 8; ++d) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (IsValid(i - dx[d], j - dy[d])) continue;
        int last_zero = -1;
        int x = i, y = j;
        double last_sum = 0;
        for (int k = 0; IsValid(x, y); ++k, x += dx[d], y += dy[d]) {
          char curr = grid[x][y];
          double lg = 0;
          if (curr == 0) {
            last_zero = k;
          } else {
            lg = log2(curr);
          }

          first_zero[d][x][y] = k - last_zero - 1;
          sum[d][x][y] = last_sum + lg;
          last_sum = sum[d][x][y];
        }
      }
    }
  }

  double max_log = 0;
  int x = 0, y = 0;
  bool rotated = false;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      for (int rot = 0; rot < 2; ++rot) {
        if (grid[i][j] == 0) continue;
        double lg;
        int k;
        GetMaxVal(i, j, rot, lg, k);
        if (lg > max_log) {
          max_log = lg;
          x = i;
          y = j;
          rotated = rot;
        }
      }
  }


  double lg;
  int k;
  GetMaxVal(x, y, rotated, lg, k);


  int ans = grid[x][y];

  for (int d = 0; d < D; ++d) {
    if (rotated != IsRotated(dx[d], dy[d])) continue;
    for (int i = 1; i <= k; ++i) {
      ans = 1LL * ans * grid[x + i * dx[d]][y + i * dy[d]] % MOD;
    }
  }

  cout << ans;

}
