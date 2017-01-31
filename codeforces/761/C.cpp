#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 55;

string s[N];

int n, m;

int IsSpecial(int c) {
  return string("#*&").find(c) != string::npos;
}

int GetFirst(int ind, int (*check)(int)) {
  int res = N;
  for (int i = 0; i < m; ++i) {
    if (!check(s[ind][i])) continue;
    res = min(res, i);
    res = min(res, m - i);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  int res = N * N;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      for (int k = 0; k < n; ++k) {
        if (k == i || k == j) continue;
        int tot = 0;
        tot += GetFirst(i, isdigit);
        tot += GetFirst(j, isalpha);
        tot += GetFirst(k, IsSpecial);

        res = min(res, tot);
      }
    }
  }

  cout << res;

}
