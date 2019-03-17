#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef unsigned long long Long;

const int N = 200005;
vector<int> groups[N];

int best_sz[N];
int best_succ[N];
bool ban[N];

int mod;
int totient;

void build() {
  for (int i = 1; i < mod; ++i) {
    int gcd = __gcd(i, mod);
    if (gcd == 1) {
      ++totient;
    }
    if (!ban[i]) {
      groups[gcd].push_back(i / gcd);
    }
  }

  memset(best_succ, -1, sizeof best_succ);
  for (int i = mod - 1; i >= 1; --i) {
    for (int j = 2 * i; j < mod; j += i) {
      if (best_sz[j] > best_sz[i]) {
        best_sz[i] = best_sz[j];
        best_succ[i] = j;
      }
    }
    best_sz[i] += groups[i].size();
  }
}

int power(int b, int p) {
  if (p == 0) return 1;
  int res = power(b, p / 2);
  res = 1LL * res * res % mod;
  if (p & 1) {
    res = 1LL * res * b % mod;
  }
  return res;
}

int modInv(int x) {
  return power(x, totient - 1);
}

vector<int> solve() {
  vector<int> res;
  int last_p = 1;
  int last_g = 1;

  for (int i = 1; i != -1; i = best_succ[i]) {
    for (int x : groups[i]) {
      int tmp = 1LL * modInv(last_p) * x % mod;

      if (last_g != i) {
        tmp = 1LL * tmp * (i / last_g) % mod;
        last_g = i;
      }
      res.push_back(tmp);
      last_p = x;
    }
  }

  if (!ban[0]) res.push_back(0);
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n >> mod;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ban[x] = true;
  }

  build();

  auto res = solve();
  cout << res.size() << endl;
  for (int x : res) {
    cout << x << " ";
  }
  cout << endl;
}

