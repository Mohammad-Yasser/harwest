#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

constexpr int N = 2e5 + 5;

Long n;

Long f(Long d) {
  Long cnt = n / d;
  Long res = cnt * (n - d) / 2 + cnt;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n;

  vector<Long> res;

  for (Long i = 1; i * i <= n; ++i) {
    if (n % i != 0) continue;
    res.push_back(f(i));
    if (i != n / i) {
      res.push_back(f(n / i));
    }
  }

  sort(res.begin(), res.end());
  for (Long x : res) {
    cout << x << " ";
  }

}
