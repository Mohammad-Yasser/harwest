#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

bool isPal(const string& s) {
  string rev = s;
  reverse(rev.begin(), rev.end());
  return s == rev;
}

const int OO = 1e9;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  string s;
  cin >> s;

  for (int i = 1; i < s.size(); ++i) {
    string tmp = s.substr(0, i);
    tmp = s.substr(i) + tmp;
    if (tmp != s && isPal(tmp)) {
      cout << 1 << endl;
      return 0;
    }
  }

  if (s.size() % 2 == 1) {
    string tmp = s.substr(0, s.size() / 2);
    tmp = s.substr(s.size() / 2 + 1) + s[s.size() / 2] + tmp;
    if (tmp != s && isPal(tmp)) {
      cout << 2;
      return 0;
    }
  }

  for (int i = 1; i <= s.size() / 2; ++i) {
    if (s.substr(0, i) != s.substr(s.size() - i)) {
      cout << 2 << endl;
      return 0;
    }
  }

  cout << "Impossible";

}
