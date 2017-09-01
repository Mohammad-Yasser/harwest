#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int k;
  cin >> k;

  vector<int> v;

  while (k > 0) {
    for (int i = 1;; ++i) {
      if (1LL * i * (i + 1) / 2 > k) {
        k -= i * (i - 1) / 2;
        v.push_back(i);
        break;
      }
    }
  }

  string res;
  for (int i = 0; i < v.size(); ++i) {
    res += string(v[i], 'a' + i);
  }

  if (res.empty()) {
    res = "a";
  }

  cout << res;

}
