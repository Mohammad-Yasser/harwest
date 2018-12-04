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

  multiset<int> ms;
  int n, k;
  cin >> n >> k;

  while (n--) {
    int x;
    cin >> x;
    ms.insert(x);
  }

  int acc = 0;

  while (k--) {
    int res = 0;
    while (!ms.empty()) {
      res = *ms.begin();
      ms.erase(ms.begin());
      res -= acc;
      acc += res;
      if (res != 0) break;
    }
    cout << res << endl;
  }

}
