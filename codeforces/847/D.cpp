#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef long double Double;

const int N = 2e5 + 5;

int arr[N];

/*
 * x + i >= t[i]
 * x >= t[i] - i
 */

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, T;
  cin >> n >> T;
  --T;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  multiset<int> ms;
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    ms.insert(arr[i] - i);
    int x = T - i;
    if (x < 0) break;
    while (!ms.empty() && *ms.rbegin() > x) {
      auto it = ms.end();
      --it;
      ms.erase(it);
    }
    res = max(res, (int) ms.size());
  }

  cout << res << endl;
}

