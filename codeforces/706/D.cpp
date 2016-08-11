#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  multiset<int> ms;

  int q;
  cin >> q;
  while (q--) {
    char c;
    int x;
    cin >> c >> x;
    if (c == '+') ms.insert(x);
    if (c == '-') ms.erase(ms.find(x));
    if (c == '?') {
      int msk = 0, ans = 0;
      for (int i = 29; i >= 0; --i) {
//        cout << "M " << msk << ' ' << (((~x >> i) & 1) << i) << endl;
        auto it = ms.lower_bound(msk | (((~x >> i) & 1) << i));
//        if (it != ms.end()) cout << *it << endl;
        if ((it != ms.end()) && (msk == ((*it) & ~((1 << (i + 1)) - 1))) &&
            ((((*it) >> i) & 1) == (1 & (~x >> i)))) {
//          cout << ((!((x >> i) & 1)) << i) << ' ' << i << endl;
          ans |= 1 << i;
          msk |= (((~x >> i) & 1) << i);
        } else
          msk |= (((x >> i) & 1) << i);
      }
      cout << max(ans, x) << '\n';
    }
  }
}
