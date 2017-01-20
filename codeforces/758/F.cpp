#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 10004;
int power[N][30];

int InitPower() {
  for (int i = 1; i < N; ++i) {
    power[i][0] = 1;
    int j;
    for (j = 1; j < 30 && power[i][j - 1] <= INT_MAX / i; ++j) {
      power[i][j] = power[i][j - 1] * i;
    }
    for (; j < 30; ++j) {
      power[i][j] = INT_MAX;
    }
  }
}

int GetLast(int first, int a, int b, int n) {
  if (n == 0) return first;
  return GetLast(first / b * a, a, b, n - 1);
}

int Solve(int l, int r, int n) {
  if (n >= 30) return 0;
  int res = 0;
  for (int i = 1; i < N; ++i) {
    int power_i = power[i][n];
    if (power_i > r) break;

    for (int k = 1; k < i; ++k) {
      int power_k = power[k][n];

      if (__gcd(i,k) != 1) continue;

      for (int last = power_i, first = power_k; last <= r;
        last += power_i, first += power_k) {
        res += (first >= l);
      }
    }
  }
  return 2 * res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("wa.txt", "w", stdout);
#endif

  InitPower();

  int n, l, r;
  cin >> n >> l >> r;

  if (n == 1) {
    cout << r - l + 1;
    return 0;
  }
  if (n == 2) {
    cout << 1LL * (r - l + 1) * (r - l);
    return 0;
  }
  cout << Solve(l, r, n - 1);
}
