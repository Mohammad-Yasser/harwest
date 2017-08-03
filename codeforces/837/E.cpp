#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

vector<Long> getDivisors(Long x) {
  vector<Long> res;
  for (Long i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      res.push_back(i);
      if (i * i != x) {
        res.push_back(x / i);
      }
    }
  }
  res.push_back(x);
  return res;
}

Long f(Long x, Long y) {
  if (y <= 1) return y;
  Long g = __gcd(x, y);
  if (g != 1) return f(x / g, y / g);
  if (x == 1) {
    return y;
  }

  auto div = getDivisors(x);

  if (div.size() == 1 && x > y) {
    return y;
  }

  Long nxt = 1;

  for (Long d : div) {
    nxt = max(nxt, y / d * d);
  }

  return y - nxt + f(x, nxt);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  Long x, y;
  cin >> x >> y;

  cout << f(x, y);
}
