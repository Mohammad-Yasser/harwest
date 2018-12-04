#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

int ask(int c, int d) {
  cout << "? " << c << " " << d << endl;
  int res;
  cin >> res;
  return res;
}

int main() {
//  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
//  freopen("test.in", "r", stdin);
#else
//#define endl '\n'
#endif

  int c = 0, d = 0;

  bool a_larger = (ask(c, d) == 1);

  vector<int> eq_idxs;

  for (int i = 29; i >= 0; --i) {
    if (a_larger) {
      if (ask(c | (1 << i), d | (1 << i)) == -1) {
        c |= (1 << i);
        a_larger = (ask(c, d) == 1);
      } else {
        eq_idxs.push_back(i);
      }
    } else {
      if (ask(c | (1 << i), d | (1 << i)) == 1) {
        d |= (1 << i);
        a_larger = (ask(c, d) == 1);
      } else {
        eq_idxs.push_back(i);
      }
    }
  }

  for (int i : eq_idxs) {
    if (ask(c | (1 << i), d) == -1) {
      c |= (1 << i);
      d |= (1 << i);
    }
  }

  cout << "! " << c << " " << d << endl;

}
