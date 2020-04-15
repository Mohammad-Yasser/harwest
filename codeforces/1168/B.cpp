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

bool valid(int mx, const vector<int>& v, int m) {
  int prev = 0;
  for (int x : v) {
    if (x < prev && prev - x > mx) return false;
    if (x > prev && m - x + prev > mx) {
      prev = x;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  string s;
  cin >> s;

  Long res = 0;

  int mn_end = s.size();
  for (int i = s.size() - 1; i >= 0; --i) {
    for (int j = i + 1; 2 * j - i < mn_end; ++j) {
      int k = 2 * j - i;
      if (s[i] == s[j] && s[j] == s[k]) {
        mn_end = k;
      }
    }
    res += s.size() - mn_end;
  }
  cout << res << endl;
  return 0;
}