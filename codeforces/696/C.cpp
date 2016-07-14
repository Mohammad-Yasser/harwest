#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const ll MOD = 1e9 + 7;

ll power(ll b, ll p) {
  ll res = 1;
  for (int i = 0; i < 64; ++i) {
    if (1 & (p >> i)) res = res * b % MOD;
    b = b * b % MOD;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  ll curr2 = 2;
  bool odd = 0;
  while (n--) {
    ll x;
    cin >> x;
    curr2 = power(curr2, x);
    if ((x & 1LL) == 0) odd = 1;
  }

  curr2 = curr2 * power(2, MOD - 2) % MOD;
  ll tmp = curr2;
  tmp = (tmp + 2 * odd - 1 + MOD) % MOD;
  tmp = (tmp * power(3, MOD - 2)) % MOD;

  cout << tmp << '/' << curr2;
}
