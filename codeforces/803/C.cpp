#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

Long nC2(Long n) {
  return n * (n + 1) / 2;
}

bool Valid(Long n, Long k) {
  return nC2(k) <= n;
}

vector<Long> GetSeq(Long n, int k) {
  vector<Long> res;
  for (int i = 1; i < k; ++i) {
    res.push_back(i);
  }
  res.push_back(n - nC2(k - 1));

  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  Long n, k;
  cin >> n >> k;

  if (k > 1e6 || !Valid(n , k)) {
    cout << -1;
    return 0;
  }



  Long d = 1;

  for (int i = 1; i <= n / i; ++i) {
    if (n % i != 0) continue;

    if (Valid(i, k)) {
      d = max(d, n / i);
    }
    if (Valid(n / i, k)) {
      d = max(d, 1LL * i);
    }
  }

  auto res = GetSeq(n / d, k);

  for (Long x : res) {
    cout << x * d << ' ';
  }

}
