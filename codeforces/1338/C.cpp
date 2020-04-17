#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)

typedef long long Long;
typedef vector<int> vi;

const int N = 1e6 + 5;

Long f(Long x) { return x - (1LL << __lg(x)); }

bool isSet(Long a, int bit) { return (a >> bit) & 1; }

array<Long, 3> solve(Long a) {
  static array<Long, 4> a_to_b;
  a_to_b[0] = 0;
  a_to_b[1] = 2;
  a_to_b[2] = 3;
  a_to_b[3] = 1;

  array<Long, 3> res = {0};
  res[0] = a;
  for (int i = 0; i < 60; i += 2) {
    int tmp = 2 * isSet(a, i + 1) + isSet(a, i);
    res[1] |= a_to_b[tmp] << i;
  }
  res[2] = res[0] ^ res[1];
  return res;
}

Long getA(Long n) {
  Long res = 1;
  while (n >= res) {
    n -= res;
    res *= 4;
  }
  return res + n;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;
  while (t--) {
    Long n;
    cin >> n;
    --n;
    Long a = getA(n / 3);
    auto res = solve(a);
    cout << res[n % 3] << endl;
  }
  return 0;
}