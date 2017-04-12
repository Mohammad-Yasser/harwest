#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

const int K = 801;
const int N = 4e3 + 1;
const int OO = 1e8;

int dp[K][N]; // dp[i][j], min cost to divide first "j" into "i" groups.

char mat[N][N];

int cost[N][N]; // cost[i][j]: cost of including exactly from "i" to "j" in one group.

int n;
void BuildCost() {
  for (int i = n; i >= 1; --i) {
    int self_cost = 0;
    for (int j = i + 1; j <= n; ++j) {
      self_cost += mat[i][j];
      cost[i][j] = self_cost + cost[i + 1][j];
    }
  }
}

void Init() {
  BuildCost();
}

void Solve(int curr_i, int k_left, int k_right, int j_left, int j_right,
  int level = 0) {
  int j_mid = (j_left + j_right) / 2;
  int& res = dp[curr_i][j_mid];
  res = OO;
  int best_k = k_left;

  for (int a = k_left; a < min(j_mid, k_right + 1); ++a) {
    int tmp = dp[curr_i - 1][a] + cost[a + 1][j_mid];
    if (tmp < res) {
      res = tmp;
      best_k = a;
    }
  }

  if (curr_i == 1) {
    res = cost[1][j_mid];
  }

  if (j_left < j_mid) {
    Solve(curr_i, k_left, best_k, j_left, j_mid - 1, level + 1);
  }
  if (j_mid < j_right) {
    Solve(curr_i, best_k, k_right, j_mid + 1, j_right, level + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int k;
  cin >> n >> k;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> mat[i][j];
      mat[i][j] -= '0';
    }
  }

  Init();

  for (int i = 1; i <= k; ++i) {
    Solve(i, 0, n, 0, n);
  }

  cout << dp[k][n] << '\n';

  return 0;
}
