#include <bits/stdc++.h>

using namespace std;

typedef long long Long;

const int N = 1e3 + 3;
const int K = 1e6 + 5;

int grid[N][N];

int rows[N];
int cols[N];

Long max_rows[K];
Long max_cols[K];

int n, m, k, p;

void BuildMax(int rows[], Long max_rows[], int n, int m) {
  priority_queue<Long> q;
  for (int i = 0; i < n; ++i) {
    q.push(rows[i]);
  }
  max_rows[0] = 0;
  for (int i = 1; i < K; ++i) {
    int curr = q.top();
    max_rows[i] = max_rows[i - 1] + curr;
    q.pop();
    q.push(curr - m * p);
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> n >> m >> k >> p;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
      rows[i] += grid[i][j];
      cols[j] += grid[i][j];
    }
  }

  BuildMax(rows, max_rows, n, m);
  BuildMax(cols, max_cols, m, n);

  Long res = LLONG_MIN;

  for (int i = 0; i <= k; ++i) {
    res = max(res, max_rows[i] + max_cols[k - i] - 1LL * i * (k - i) * p);
  }

  cout << res;
}
