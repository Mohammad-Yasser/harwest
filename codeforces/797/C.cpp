#include<bits/stdc++.h>
using namespace std;

const int A = 128;

string s;
string t;
string u;

int cnt[A];

int main() {
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> s;
  reverse(s.begin(), s.end());

  for (char& c : s) {
    ++cnt[c];
  }

  for (char c = 'a'; c <= 'z'; ++c) {
    while (!t.empty() && t.back() <= c) {
      u += t.back();
      t.pop_back();
    }

    while (cnt[c] > 0) {
      if (s.back() == c) {
        u += c;
      } else {
        t += s.back();
      }

      --cnt[s.back()];
      s.pop_back();
    }
  }

  cout << u << '\n';

  return 0;
}
