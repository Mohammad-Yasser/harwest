#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int MX = 1e9 + 1;
const int SQ = sqrt(MX) + 3;
const int CQ = pow(MX, 1.0 / 3) + 3;

bool prime[SQ];

vector<int> primes;

bool isPrime(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) return false;
  }
  return true;
}

void build() {
  for (int i = 2; i < SQ; ++i) {
    prime[i] = isPrime(i);
    if (prime[i]) {
      primes.push_back(i);
    }
  }
}

vector<pair<int, int>> factorize(int x) {
  vector<pair<int, int>> res;
  for (int i : primes) {
    if (i >= CQ) break;
    int cnt = 0;
    while (x % i == 0) {
      ++cnt;
      x /= i;
    }
    if (cnt == 0) continue;
    res.emplace_back(i, cnt);
  }
  if (x != 1) {
    res.emplace_back(x, 1);
  }
  return res;
}

/*
 * a = 2 * x + y
 * b = 2 * y + x
 *
 * 2 * a - b = 3 x
 *
 */

bool valid(const vector<pair<int, int>>& a, const vector<pair<int, int>>& b) {
  if (a.size() != b.size()) return false;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i].first >= CQ) {
      int x = a[i].first;
      int y = b[i].first;

      if (x > y) swap(x, y);

      return x < SQ && x * x == y;
    }
    if (a[i].first != b[i].first) return false;
    int c = 2 * a[i].second - b[i].second;
    if (c % 3 != 0) return false;
    int x = c / 3;
    if (x < 0) return false;
    int y = a[i].second - 2 * x;
    if (y < 0) return false;
  }
  return true;
}

bool valid(int a, int b) {
  if (a > b) swap(a, b);
  if (b == 1) return true;
  if (a == 1) return false;

  auto factors_a = factorize(a);
  auto factors_b = factorize(b);

  return valid(factors_a, factors_b);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  build();

  int n;
  cin >> n;

  while (n--) {
    int a, b;
    cin >> a >> b;

    cout << (valid(a, b) ? "YES\n" : "NO\n");
  }

}
