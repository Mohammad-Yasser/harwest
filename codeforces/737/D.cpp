#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 4003;
/*
 N >= K * (K + 1) / 2
 2 * N >= K * K + K
 sqrt(2 * N) >= sqrt(K * K + K)
 sqrt(2 * N) >= K
 */
const int K = sqrt(2 * N) + 2;
const int kShift = 9e8;
int arr[N];
int acc[N];
int memo[N][K][K][2];

int n;

// acc[0] = 0
// acc[i] = arr[i - 1] + ..

int GetRangeSum(int left, int right) {
  return acc[right + 1] - acc[left];
}

int Solve(int left, int right, int k, bool left_turn) {
  if (right - left + 1 < k) return 0;
  int diff = n - 1 - right - left;
  if (!left_turn) {
    diff += k;
  }
  int &ret = memo[left][diff][k][left_turn];
  assert(ret >= -1);
  if (ret != -1) return ret - kShift;

  if (left_turn) {
    ret = GetRangeSum(left, left + k - 1) + Solve(left + k, right, k, false);
    if (right - left + 1 >= k + 1) {
      ret = max(ret,
        GetRangeSum(left, left + k) + Solve(left + k + 1, right, k + 1, false));
    }
  } else {
    ret = -GetRangeSum(right - k + 1, right) + Solve(left, right - k, k, true);
    if (right - left + 1 >= k + 1) {
      ret = min(ret,
        -GetRangeSum(right - k, right)
          + Solve(left, right - k - 1, k + 1, true));
    }
  }

//  cout << left << ' ' << right << ' ' << k << ' ' << left_turn << ' ' << ret << endl;

  ret += kShift;
  return ret - kShift;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  memset(memo, -1, sizeof memo);
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    acc[i + 1] = acc[i] + arr[i];
  }

  cout << Solve(0, n - 1, 1, true);

}
