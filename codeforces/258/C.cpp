#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;
const int N = 100005;

int power(int base, int exp) {
  int res = 1;
  int curr = base;
  for (int i = 0; i < 32; ++i) {
    if ((exp >> i) & 1) {
      res = 1LL * res * curr % MOD;
    }
    curr = 1LL * curr * curr % MOD;
  }
  return res;
}

int cnt[N];

int Calc(int lcm) {
  vector<int> divisors;
  for (int i = 1; i * i <= lcm; ++i) {
    if (lcm % i == 0) {
      divisors.push_back(i);
      if (i * i != lcm) {
        divisors.push_back(lcm / i);
      }
    }
  }

  sort(divisors.begin(), divisors.end());

  int res = (power(divisors.size(), cnt[lcm])
    - power(divisors.size() - 1, cnt[lcm]) + MOD) % MOD;
  int prev_count = cnt[lcm];

  for (int i = divisors.size() - 2; i >= 0; --i) {
    res = (1LL * res * power(i + 1, cnt[divisors[i]] - prev_count)) % MOD;
    prev_count = cnt[divisors[i]];

  }

  return res;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("test.in", "rt", stdin);
//  freopen("o.txt", "wt", stdout);
#endif

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++cnt[x];
  }

  for (int i = N - 2; i >= 0; --i) {
    cnt[i] += cnt[i + 1];
  }

  int res = 1;

  for (int i = N - 1; i > 1; --i) {
    res = (res + Calc(i)) % MOD;
  }

  cout << res;

  return 0;
}
