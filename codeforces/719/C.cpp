#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n, t;
  cin >> n >> t;
  string s;
  cin >> s;
  s = "0" + s;
  t = min(t, (int)s.size());

  int dot;

  for (int i = 0; i < s.size(); ++i)
    if (s[i] == '.') dot = i;

  int pos = -1;

  for (int i = dot + 1; i < s.size(); ++i) {
    if (s[i] >= '5') {
      pos = i;
      break;
    }
  }

  if (pos == -1) {
    if (s[0] == '0') s.erase(s.begin());
    cout << s;
    return 0;
  }

  while (pos > dot && s[pos] >= '5' && t--) {
    if (pos - 1 == dot) {
      int tmp = pos;
      tmp -= 2;
      while (s[tmp] == '9') {
        s[tmp] = '0';
        --tmp;
      }
      ++s[tmp];
      --pos;
    } else {
      ++s[pos - 1];
    }
    --pos;
  }

  s = s.substr(0, pos + 1);
  if (s[0] == '0') s.erase(s.begin());

  cout << s;

  return 0;
}
