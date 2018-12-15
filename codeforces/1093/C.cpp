#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  vector<Long> b(n / 2), a(n);
  for (Long& x : b) {
    cin >> x;
  }
  a[0] = 0, a[n - 1] = b[0];
  for (int i = 1; i < n / 2; ++i) {
    int j = n - i - 1;
    Long mn = max(a[i - 1], b[i] - a[j + 1]);
    a[i] = mn;
    a[j] = b[i] - mn;
  }

  for (Long& x : a) {
    cout << x << " ";
  }
}
