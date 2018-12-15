#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s[0] == s.back()) {
      cout << -1 << endl;
    } else {
      cout << s << endl;
    }
  }

}
