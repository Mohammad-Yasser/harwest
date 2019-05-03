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

const int N = 8e3 + 5;
const int MOD = 179424673;
const int kBase[2] = { 27, 29 };

int base_power[N];

int hashes[N];
string s;

void buildHashes() {
  base_power[0] = 1;
  for (int i = 1; i < N; ++i) {
    base_power[i] = 1LL * base_power[i - 1] * kBase[0] % MOD;
  }

  for (char& c : s) {
    ++c;
    c -= 'a';
  }

  hashes[0] = 1;
  for (int i = 0; i < s.size(); ++i) {
    hashes[i + 1] = (1LL * hashes[i] * kBase[0] + s[i]) % MOD;
  }
}

int getRangeFor(int l, int r) {
  ++l, ++r;
  int res = hashes[r];
  int tmp_l = 1LL * hashes[l - 1] * base_power[r - l + 1] % MOD;
  res = (res - tmp_l + MOD) % MOD;
  return res;
}

int cnt[N][N];

void buildCnt() {
  for (int i = s.size() - 1; i >= 0; --i) {
    for (int j = i; j < s.size(); ++j) {
      cnt[i][j] = 1;

      if (j + 1 + j - i < s.size()
        && getRangeFor(i, j) == getRangeFor(j + 1, j + 1 + j - i)) {
        cnt[i][j] += cnt[j + 1][j + 1 + j - i];
      }
    }
  }
}

int memo[N];
int solve(int ind) {
  if (ind == s.size()) return 0;
  int& res = memo[ind];
  if (res != -1) return res;
  res = N;

  for (int i = ind; i < s.size(); ++i) {
    int number_length = 1;
    int nxt_power = 10;
    for (int j = 1; j <= cnt[ind][i]; ++j) {
      if (j == nxt_power) {
        ++number_length;
        nxt_power *= 10;
      }
      res = min(res,
        number_length + (i - ind + 1) + solve(ind + j * (i - ind + 1)));
    }
  }

  return res;
}

int main() {
  srand(time(0));
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  memset(memo, -1, sizeof memo);
  cin >> s;
  buildHashes();
  buildCnt();

  cout << solve(0) << endl;

}
