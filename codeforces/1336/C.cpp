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
#define all(v) begin(v), end(v)

typedef long long Long;
typedef vector<int> vi;

const int N = 3003;
const int MOD = 998244353;

string t, s;

int memo[N][N][2];

int solve(int s_ind, int z, bool is_substring) {
  int& res = memo[s_ind][z][is_substring];
  if (res != -1) return res;
  res = 0;

  if (z == 0 && (!is_substring || s_ind == t.size())) {
    res = 1;
  }

  if (s_ind == s.size()) {
    return res;
  }

  // Back
  if (z != 0 && t[z - 1] == s[s_ind]) {
    res = (res + solve(s_ind + 1, z - 1, is_substring)) % MOD;
  }
  if (z == t.size()) {
    res = (res + solve(s_ind + 1, z, is_substring)) % MOD;
  }

  // Front
  if (is_substring) {
    if (z + s_ind == t.size()) {
      res = (res + solve(s_ind + 1, z, false)) % MOD;
    } else if (t[z + s_ind] == s[s_ind]) {
      res = (res + solve(s_ind + 1, z, true)) % MOD;
    }
  } else {
    res = (res + solve(s_ind + 1, z, false)) % MOD;
  }
  // cout << s_ind << " " << z << " " << is_substring << " " << res << endl;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> s >> t;
  memset(memo, -1, sizeof memo);
  int res = solve(1, t.size(), false);
  for (int z = 0; z < t.size(); ++z) {
    if (t[z] == s[0]) {
      res = (res + solve(1, z, true)) % MOD;
    }
  }
  res = 2 * res % MOD;
  cout << res << endl;
  return 0;
}
