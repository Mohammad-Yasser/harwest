#include <bits/stdc++.h>
using namespace std;

int a[2][2];
int n[2];
int tmpa[2][2];

string ans;

bool solve2(int x0, int x1) {
  ans = "";
  if (!x1) {
    if (a[0][1] || a[1][0]) return false;
    ans = string(x0, '0');
    return true;
  }

  for (int i = 0; i < a[0][1] / x1 && x0 >= 0; ++i) ans += "0", --x0;
  for (int i = 0; i < x1 - (a[0][1] % x1); ++i) ans += "1";

  if (x0 < 0) return false;

  if (x0) ans += "0", --x0;
  for (int i = 0; i < a[0][1] % x1; ++i) ans += "1";

  while (x0--) ans += "0";
  int n0 = 0, n1 = 0;
  for (int i = 0; i < ans.size(); ++i) {
    if (ans[i] == '0') {
      tmpa[0][0] -= n0;
      tmpa[1][0] -= n1;
      ++n0;
    } else {
      tmpa[1][1] -= n1;
      tmpa[0][1] -= n0;
      ++n1;
    }
  }

  bool zer = 1;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      if (tmpa[i][j]) zer = 0;
  return zer;
}

bool solve() {
  // n[i] * (n[i] - 1) / 2 == a[i][i]
  for (int i = 0; i < 2; ++i) {
    n[i] = 0;
    while (n[i] * (n[i] - 1) / 2 < a[i][i]) ++n[i];
    if (n[i] * (n[i] - 1) / 2 != a[i][i]) return false;
  }
  int op0[2] = {n[0], max(1, n[0])}, op1[2] = {n[1], max(1, n[1])};

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      if (max(op0[i], op1[j])) {
        for (int ii = 0; ii < 2; ++ii)
          for (int jj = 0; jj < 2; ++jj) tmpa[ii][jj] = a[ii][jj];

        if (solve2(op0[i], op1[j])) return true;
      }
  return false;
}

void stress() {
  int cs = 0;
  while (++cs) {
    cerr << cs << endl;
    int n = 1e5 + (rand() % 2);
    string res;
    res.resize(n);
    memset(a, 0, sizeof a);
    int n0 = 0, n1 = 0;
    for (int i = 0; i < n; ++i) {
      res[i] = '0' + (rand() % 2);
      if (res[i] == '0') {
        a[0][0] += n0;
        a[1][0] += n1;
        ++n0;
      } else {
        a[1][1] += n1;
        a[0][1] += n0;
        ++n1;
      }
    }
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j) tmpa[i][j] = a[i][j];
    bool solved = solve();
    n0 = 0, n1 = 0;
    for (int i = 0; i < ans.size(); ++i) {
      if (ans[i] == '0') {
        tmpa[0][0] -= n0;
        tmpa[1][0] -= n1;
        ++n0;
      } else {
        tmpa[1][1] -= n1;
        tmpa[0][1] -= n0;
        ++n1;
      }
    }
    bool zer = 1;
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        if (tmpa[i][j]) zer = 0;
    if (!solved || !zer) {
      cout << solved << endl;
      cout << ans << endl << res;
      return;
    }
  }
}

int main() {
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) cin >> a[i][j];

  if (solve())
    cout << ans;
  else
    cout << "Impossible";
}
