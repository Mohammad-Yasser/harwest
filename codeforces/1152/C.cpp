#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

Long lcm(Long a, Long b) {
  return a / __gcd(a, b) * b;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  Long a, b;
  cin >> a >> b;

  if (a > b) {
    swap(a, b);
  }

  Long best_k = 0;
  Long best_lcm = lcm(a, b);
  Long d = b - a;

  for (int i = 1; i * i <= d; ++i) {
    if (d % i != 0) continue;
    Long k = (i - a % i) % i;

    if (lcm(a + k, b + k) < best_lcm) {
      best_lcm = lcm(a + k, b + k);
      best_k = k;
    }
    if (lcm(a + k, b + k) == best_lcm) {
      best_k = min(k, best_k);
    }

    k = (d / i - a % (d / i)) % (d / i);
    if (lcm(a + k, b + k) < best_lcm) {
      best_lcm = lcm(a + k, b + k);
      best_k = k;
    }
    if (lcm(a + k, b + k) == best_lcm) {
      best_k = min(k, best_k);
    }
  }

  cout << best_k << endl;

}
