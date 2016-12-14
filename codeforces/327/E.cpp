#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 24;
const int MOD = 1000000007;

int dp[1 << N];
int a[N];
int unwanted[2];
int n;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int k;
  cin >> k;

  for (int i = 0; i < k; ++i) {
    cin >> unwanted[i];
  }

  for (int mask = (1 << n) - 1; mask >= 0; --mask) {
    int sum = 0;
    int res = (mask == (1 << n) - 1);
    for (int i = 0; i < n; ++i) {
      if ((mask >> i) & 1) {
        if (sum <= 1e9) {
          sum += a[i];
        }
      } else {
        res += dp[mask | (1 << i)];
        if (res > MOD) res -= MOD;
      }

    }

    if (sum && (sum == unwanted[0] || sum == unwanted[1])) {
      dp[mask] = 0;
      continue;
    }

    dp[mask] = res;
  }

  cout << dp[0];

}
