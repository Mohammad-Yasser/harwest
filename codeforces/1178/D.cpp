#ifndef Local
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int MOD = 998244353;

const int N = 2003;

vector<int> primes;
bool nonPrime[N];

void buildPrimes() {
  for (int i = 2; i < N; ++i) {
    if (nonPrime[i]) continue;
    if (i != 2) {
      primes.push_back(i);
    }
    for (int j = 2 * i; j < N; j += i) {
      nonPrime[j] = true;
    }
  }
}

int nxt[N];

bool valid(int n) {
  if (n <= 2) return false;
  if (!nonPrime[n]) return true;
  for (int x : primes) {
    if (valid(n - x)) {
      nxt[n] = x;
      return true;
    }
  }
  return false;
}

vector<int> getSizes(int n) {
  vector<int> res;
  while (n != 0) {
    if (!nonPrime[n]) {
      res.push_back(n);
    } else {
      res.push_back(3);
    }
    n -= res.back();
  }
  assert(n == 0);
  return res;
}

bool connected[N][N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  buildPrimes();

  int n;
  cin >> n;

  if (n == 4) {
    cout << "5\n1 2\n1 3\n2 3\n2 4\n3 4" << endl;
    return 0;
  }

  auto sz = getSizes(n);

  vector<pair<int, int>> res;

  int curr = 1;
  for (int x : sz) {
    for (int i = 0; i < x; ++i) {
      int j = (i + 1) % x;
      res.emplace_back(curr + i, curr + j);
      connected[curr + i][curr + j] = true;
      connected[curr + j][curr + i] = true;
    }
    curr += x;
  }

  set<int> st;
  for (int i = 1; i <= n; ++i) {
    st.insert(i);
  }

  while (nonPrime[n]) {
    int y = *st.begin();
    for (int x : st) {
      if (x == y) continue;
      if (!connected[y][x]) {
        st.erase(x);
        st.erase(y);
        res.emplace_back(x, y);
        break;
      }
    }
    ++n;
  }

  cout << res.size() << endl;

  for (auto& p : res) {
    cout << p.first << " " << p.second << endl;
  }

}
