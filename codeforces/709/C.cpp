#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool started = false;
  bool end = false;

  for (char &x : s) {
    if (x != 'a') started = true;
    if (started && x == 'a') end = true;
    if (started && !end) --x;
  }

  if (!started) s[s.size() - 1] = 'z';

  cout << s;
}
