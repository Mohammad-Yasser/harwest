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

  string s;
  cin >> s;

  bool can = false;
  for (int i = 0; i < 5; ++i) {
    string tmp;
    cin >> tmp;
    if (s[0] == tmp[0] || s[1] == tmp[1]) {
      can = true;
    }
  }

  if (can) {
    cout << "YES";
  } else {
    cout << "NO";
  }

}
