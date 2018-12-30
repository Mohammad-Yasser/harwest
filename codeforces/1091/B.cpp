#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

constexpr int N = 2e5 + 5;

pair<int, int> a[N], b[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }

  for (int i = 0; i < n; ++i) {
    cin >> b[i].first >> b[i].second;
  }

  sort(a, a + n);
  sort(b, b + n);

  cout << a[0].first + b[n - 1].first << " " << a[0].second + b[n - 1].second;

}
