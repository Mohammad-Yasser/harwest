#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  string s;
  string s_r;
  string s_b;

  cin >> s;
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      s_r += 'r';
      s_b += 'b';
    } else {
      s_r += 'b';
      s_b += 'r';
    }
  }

  int cntR = 0, cntB = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != s_r[i]) {
      if (s[i] == 'r')
        ++cntR;
      else
        ++cntB;
    }
  }

  int ans = max(cntR, cntB);

  cntR = 0, cntB = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != s_b[i]) {
      if (s[i] == 'r')
        ++cntR;
      else
        ++cntB;
    }
  }

  ans = min(ans, max(cntR, cntB));

  cout << ans;

  return 0;
}
