#include <bits/stdc++.h>
using namespace std;

const int A = 'z' - 'a' + 1;

int main() {
  ios_base::sync_with_stdio(false);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < (k + 1) / 2; ++i) {
      vector<int> cnt(A, 0);
      int total = 0;
      for (int j1 = i, j2 = k - 1 - i; j2 < n; j1 += k, j2 += k) {
        ++cnt[s[j1] - 'a'];
        ++total;
        if (j1 != j2) {
          ++cnt[s[j2] - 'a'];
          ++total;
        }
      }
      res += total - *max_element(begin(cnt), end(cnt));
    }
    cout << res << endl;
  }
  return 0;
}
