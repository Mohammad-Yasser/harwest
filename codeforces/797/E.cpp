#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int kSqrtN = sqrt(N) + 3;
int a[N];

int answers[N][kSqrtN]; // answer[p][k]

int n;

void Solve() {
  for (int i = N - 1; i >= 0; --i) {
    for (int j = 0; j < kSqrtN; ++j) {
      if (i + a[i] + j > n) {
        answers[i][j] = 1;
      } else {
        answers[i][j] = 1 + answers[i + a[i] + j][j];
      }
    }
  }
}

int main() {
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  Solve();

  int q;
  cin >> q;

  while (q--) {
    int p, k;
    cin >> p >> k;

    if (k < kSqrtN) {
      cout << answers[p][k] << '\n';
    } else {
      int res = 0;
      while (p <= n) {
        p += a[p] + k;
        ++res;
      }
      cout << res << '\n';
    }
  }

  return 0;
}
