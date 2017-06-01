#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 1e3;

string grid[N];

int n, m;

int memo[N][2];

int Solve(int floor, bool left) {
  if (floor == n) return 0;
  int& res = memo[floor][left];
  if (res != -1) return res;

  res = m + Solve(floor + 1, !left);
  int tmp;

  if (left) {
    tmp = 0;
    for (int i = 0; i < m; ++i) {
      if (grid[floor][i] == '1') {
        tmp = i;
      }
    }
  } else {
    tmp = m - 1;
    for (int i = m - 1; i >= 0; --i) {
      if (grid[floor][i] == '1') {
        tmp = i;
      }
    }
    tmp = m - 1 - tmp;
  }

  res = min(res, 2 * tmp + Solve(floor + 1, left) + 1);

  if (floor == n - 1) {
    res = tmp;
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  memset(memo, -1, sizeof memo);

  cin >> n >> m;

  m += 2;

  for (int i = n - 1; i >= 0; --i) {
    cin >> grid[i];
  }

  while (n > 0 && grid[n - 1].find('1') == string::npos) {
    --n;
  }

  cout << Solve(0, true);
}
