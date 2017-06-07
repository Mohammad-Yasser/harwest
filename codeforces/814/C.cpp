#include <bits/stdc++.h>

using namespace std;

const int N = 1501;
const int A = 26;

int res[A][N];

string s;

void Build(char c) {
  for (int i = 0; i < s.size(); ++i) {
    int last = i;
    for (int m = 1; m < N; ++m) {
      bool used = false;

      while (last < s.size() && (s[last] == c || !used)) {
        used |= (s[last] != c);
        ++last;
      }

      res[c - 'a'][m] = max(res[c - 'a'][m], last - i);
    }
  }
}

void Build() {
  for (char c = 'a'; c <= 'z'; ++c) {
    Build(c);
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> s >> s;

  Build();

  int q;
  cin >> q;

  while (q--) {
    int m;
    char c;
    cin >> m >> c;

    cout << res[c - 'a'][m] << '\n';
  }

  return 0;
}
