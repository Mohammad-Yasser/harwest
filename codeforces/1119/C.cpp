#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 505;

bool a[N][N];
bool b[N][N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> b[i][j];
    }
  }

  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j + 1 < m; ++j) {
      if (a[i][j] != b[i][j]) {
        a[i][j] ^= 1;
        a[i + 1][j] ^= 1;
        a[i + 1][j + 1] ^= 1;
        a[i][j + 1] ^= 1;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != b[i][j]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes";

}

