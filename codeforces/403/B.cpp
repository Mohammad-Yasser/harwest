#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("popcnt,abm,mmx,avx2")
#endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define rep(i, l, r) for (int i = l; i < r; ++i)
typedef long long Long;
typedef double Double;

template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

using vi = vector<int>;
const int N = 5003;

// Source: kactl
constexpr int MAX_PR = 31627;
bitset<MAX_PR> isprime;
unordered_set<int> bad_primes;
vi primes;
void eratosthenesSieve(int lim = MAX_PR) {
  isprime.set();
  isprime[0] = isprime[1] = 0;
  for (int i = 4; i < lim; i += 2) isprime[i] = 0;
  for (int i = 3; i * i < lim; i += 2)
    if (isprime[i])
      for (int j = i * i; j < lim; j += i * 2) isprime[j] = 0;
  rep(i, 2, lim) if (isprime[i]) primes.push_back(i);
}

template <class T>
vector<pair<T, int>> getPrimeFactorization(T n) {
  vector<pair<T, int>> res;
  for (int i : primes) {
    if (n % i != 0) continue;
    if (n < i * i) break;
    res.emplace_back(i, 0);
    while (n % i == 0) {
      ++res.back().second;
      n /= i;
    }
  }
  if (n != 1) {
    res.emplace_back(n, 1);
  }
  return res;
}

int getSmallestPrimeDiv(int n) {
  for (int i : primes) {
    if (n % i == 0) return i;
    if (n < i * i) break;
  }
  return n;
}

int arr[N];
int prefix_gcd[N];
unordered_map<int, int> memo_f;
int f(int n) {
  if (n == 1) return 0;
  auto it = memo_f.find(n);
  if (it != end(memo_f)) return it->second;
  int smallest_prime_div = getSmallestPrimeDiv(n);
  int res = f(n / smallest_prime_div);
  if (bad_primes.find(smallest_prime_div) != end(bad_primes)) {
    --res;
  } else {
    ++res;
  }
  return memo_f[n] = res;
}

int memo[N][N];
int n;

int solve() {
  memo[0][0] = max(f(arr[0]), f(1));
  for (int i = 0; i < n; ++i) {
    if (i != 0) {
      memo[i][i] = f(arr[i] / prefix_gcd[i]) + memo[i - 1][i];
      memo[i][0] = max(f(arr[i]) + memo[i - 1][0], memo[i][i]);
    }
    for (int j = i + 1; j < n; ++j) {
      memo[i][j] = max(memo[i][i], f(arr[i] / prefix_gcd[j]) +
                                       (i == 0 ? 0 : memo[i - 1][j]));
    }
  }
  return memo[n - 1][0];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif
  eratosthenesSieve();
  int m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  prefix_gcd[0] = arr[0];
  for (int i = 1; i < n; ++i) {
    prefix_gcd[i] = __gcd(prefix_gcd[i - 1], arr[i]);
  }
  while (m--) {
    int x;
    cin >> x;
    bad_primes.emplace(x);
  }
  cout << solve() << endl;

  return 0;
}