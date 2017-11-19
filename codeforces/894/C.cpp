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

  int n;
  cin >> n;

  vector<int> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    if (i != 0 && v[i] % v[0] != 0) {
      cout << -1;
      return 0;
    }
  }

  cout << 2 * n << endl;
  for (int i = 0 ; i < n ; ++i) {
    cout << v[0] << " " << v[i] << " ";
  }



}

