#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef long double Double;

const int N = 103;
int memo[N];

bool is_prime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int solve(int n) {
  if (n == 0) return 0;
  int& res = memo[n];
  if (res != -1) return res;

  res = -2;
  for (int i = 2; i <= n; ++i) {
    if (!is_prime(i) && solve(n - i) != -2) {
      res = max(res, 1 + solve(n - i));
    }
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  memset(memo, -1, sizeof memo);
  int q;
  cin >> q;

  while (q--) {
    int x;
    cin >> x;

    int f = max(x / 4 - 5, 0);

    int rem = x - 4 * f;

    if (solve(rem) == -2) {
      cout << -1 << endl;
    } else {
      cout << f + solve(rem) << endl;
    }
  }

  return 0;
}

