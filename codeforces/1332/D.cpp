#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int k;
  cin >> k;

  cout << 2 << " " << 3 << endl;

  cout << (1 << 18) - 1 << " " << k << " " << 0 << endl;
  cout << (1 << 17) << " " << (1 << 18) - 1 << " " << k << endl;

  return 0;
}
