#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = 1e6 + 5;
const int MOD = 998244353;

Long f(Long n) {
  vector<Long> p;
  vector<Long> v;
  for (int i = 1; i <= n; ++i) {
    v.push_back(i);
  }
  do {
    p.insert(p.end(), v.begin(), v.end());
  } while (next_permutation(v.begin(), v.end()));

  Long res = 0;
  map<int, int> cnt;
  for (int i = 0; i + n <= p.size(); ++i) {
    Long sum = 0;
    for (int j = i; j < i + n; ++j) {
      sum += p[j];
    }
    if (sum == n * (n + 1) / 2) {
      ++cnt[i % n];
//      cout << i << " " << i % n << endl;
    }
    res += (sum == n * (n + 1) / 2);
  }
//  cout << "+====================" << endl;
  for (int i = n - 1; i >= 0; --i) {
//    cout << i << " " << cnt[i] << " " << cnt[i] / n << endl;
  }

  return res;
}

Long fact[N];

Long f2(Long n) {
  Long res = 1;
  for (int i = 1; i <= n; ++i) {
    res = ((res * i) % MOD + fact[i] - i + MOD) % MOD;
  }
  return res;
}

void build() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  build();
  Long n;
  cin >> n;
  cout << f2(n);

}
