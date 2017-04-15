#include<bits/stdc++.h>
using namespace std;

int main() {
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  int max_even = 0, max_odd = INT_MIN / 2;

  while (n--) {
    int x;
    cin >> x;

    if (x & 1) {
      int old_even = max_even;
      max_even = max(max_even, x + max_odd);
      max_odd = max(max_odd, x + old_even);

      max_odd = max(max_odd, x);
    } else {
      max_even = max(max_even, x + max_even);
      max_odd = max(max_odd, x + max_odd);

      max_even = max(max_even, x);
    }
  }

  cout << max_odd << '\n';

  return 0;
}
