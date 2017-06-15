#include <bits/stdc++.h>

using namespace std;

const int MOD = round(1e9 + 7);
typedef long long Long;

const int N = 1e6 + 5;

int arr[N];

int first[N][2]; // left, right

int n;

void BuildFirst() {
  arr[0] = arr[n + 1] = 1e7;

  for (int d = 0; d < 2; ++d) {
    for (int i = (d == 0 ? 1 : n); i > 0 && i <= n; i -= 2 * d - 1) {
      int& f = first[i][d];
      f = i + 2 * d - 1;
      while (arr[f] < arr[i] || (d == 1 && arr[f] == arr[i])) {
        f = first[f][d];
      }
    }
  }
}

Long Solve() {
  Long res = 0;

  for (int sign = 0; sign < 2; ++sign) {
    BuildFirst();
    for (int i = 1; i <= n; ++i) {
      res += 1LL * (i - first[i][0]) * (first[i][1] - i) * arr[i];
      arr[i] *= -1;
    }
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> n;
  for (int i = 1 ; i <= n ; ++i) {
    cin >> arr[i];
  }

  cout << Solve();

  return 0;
}
