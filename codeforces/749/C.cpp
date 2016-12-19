#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("test.in", "rt", stdin);
//  freopen("o.txt", "wt", stdout);
#endif

  int n;
  cin >> n;
  string s;
  cin >> s;

  set<int> parties[2];
  for (int i = 0; i < s.size(); ++i) {
    parties[s[i] == 'D'].insert(i);
  }
  parties[0].insert(s.size());
  parties[1].insert(s.size());

  int curr = 0;

  while (min(parties[0].size(), parties[1].size()) > 1) {
    curr = min(*parties[0].lower_bound(curr), *parties[1].lower_bound(curr));
    if (curr == s.size()) {
      curr = 0;
      continue;
    }
    bool enemy = (s[curr] != 'D');
    int dec = *parties[enemy].lower_bound(curr);
    if (dec == s.size()) {
      dec = *parties[enemy].begin();
    }
    parties[enemy].erase(dec);
    ++curr;
  }

  if (parties[1].size() > parties[0].size()) {
    cout << "D\n";
  } else {
    cout << "R\n";
  }

  return 0;
}

