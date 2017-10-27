#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n, x;
  cin >> n >> x;

  Long sum = n - 1;

  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    sum += tmp;
  }

  cout << (sum == x ? "YES" : "NO");
}

