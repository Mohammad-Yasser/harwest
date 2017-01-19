#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s;

int Evaluate(int beg) {
  if (beg + 1 < s.size() && s[beg] == 0) return n;
  ll res = 0;
  for (int i = beg; i < s.size(); ++i) {
    res = res * 10 + s[i];
    if (res > n) return n;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  cin >> n >> s;
  for (char& c : s) {
    c -= '0';
  }
  ll res = 0;
  ll n_power = 1;

  while (!s.empty()) {
    for (int i = 0; i < s.size(); ++i) {
      int digit = Evaluate(i);
      if (digit < n) {
        res += n_power * digit;
        n_power *= n;
        s.erase(s.begin() + i, s.end());
        break;
      }
    }
  }

  cout << res;
}

