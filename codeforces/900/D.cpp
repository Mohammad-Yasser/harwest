#include <bits/stdc++.h>

using namespace std;
#define popCnt(x) (__builtin_popcount(x))

const int MOD = round(1e9 + 7);

int power(int base, int p) {
  if (p == 0) return 1;
  int res = power(base, p / 2);
  res = 1LL * res * res % MOD;
  if (p & 1) res = 1LL * res * base % MOD;
  return res;
}

vector<int> getDiv(int x) {
  vector<int> res;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      res.push_back(i);
      if (x / i != i) {
        res.push_back(x / i);
      }
    }
  }
  sort(res.rbegin(), res.rend());
  return res;
}

const int N = 1e4 + 5;
int ways[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int x, y;
  cin >> x >> y;

  if (y % x != 0) {
    cout << 0;
    return 0;
  }

  y /= x;

  auto divs = getDiv(y);

  int res = 0;

  for (int i = 0; i < divs.size(); ++i) {
    ways[i] = power(2, y / divs[i] - 1);
    for (int j = 0; j < i; ++j) {
      if (divs[j] % divs[i] == 0) {
        ways[i] = (ways[i] - ways[j] + MOD) % MOD;
      }
    }
  }

  cout << ways[divs.size() - 1];

}
