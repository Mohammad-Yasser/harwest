#include <bits/stdc++.h> 
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  cout << n / 2 * 2 + (n + 1) / 2 << endl;

  for (int i = 2 ; i <= n ; i += 2) {
    cout << i << " ";
  }

  for (int i = 1 ; i <= n ; i += 2) {
    cout << i << " ";
  }

  for (int i = 2 ; i <= n ; i += 2) {
    cout << i << " ";
  }

}
