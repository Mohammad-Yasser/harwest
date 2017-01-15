#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool IsPrime(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  int n;
  cin >> n;

  for (int i = 1;; ++i) {
    int tmp = i * n + 1;
    if (!IsPrime(tmp)) {
      cout << i << '\n';
      return 0;
    }
  }

}
