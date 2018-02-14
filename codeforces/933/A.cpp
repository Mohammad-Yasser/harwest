#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

const int N = 2e3 + 3;

int arr[N];
int rev[N];

int lis[N][N];
int cnt_1[N];
int n;

void buildLis() {
//  for (int i = 1; i <= n; ++i) {
//    cout << rev[i] << " ";
//  }
//  cout << endl;

  for (int i = 1; i <= n; ++i) {
    int ones = 0;
    int twos = 0;
    int res = 0;

    for (int j = i; j <= n; ++j) {
      if (rev[j] == 1)
        ++ones;
      else
        ++twos;

      if (ones > res) {
        res = ones;
      } else {
        res += (rev[j] == 2);
      }

      lis[n + 1 - j][n + 1 - i] = res;
    }
  }
}

void buildCnt() {
  int ones = 0;
  for (int i = 1; i <= n; ++i) {
    ones += (arr[i] == 1);
    cnt_1[i] = ones;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    rev[i] = arr[i];
  }

  reverse(rev + 1, rev + n + 1);

  buildLis();
  buildCnt();

  int res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      int tmp = cnt_1[i - 1] + ((n - j) - (cnt_1[n] - cnt_1[j])) + lis[i][j];
      res = max(res, tmp);

//      cout << i << " " << j << " " << cnt_1[i - 1] << " "
//        << ((n - j) - (cnt_1[n] - cnt_1[j])) << " " << lis[i][j] << " " << tmp
//        << endl;
    }
  }

  cout << res << endl;
}

