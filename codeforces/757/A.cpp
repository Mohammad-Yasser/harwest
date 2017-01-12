#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string bal = "Bulbasaur";
int cnt[128];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("wa.txt", "w", stdout);
#endif

  string s;
  cin >> s;

  int res = 1e7;

  for (int c : s) {
    ++cnt[c];
  }

  for (int c : bal) {
    int tmp = count(bal.begin(), bal.end(), c);
    res = min(res, cnt[c] / tmp);
  }

  cout << res;

}
