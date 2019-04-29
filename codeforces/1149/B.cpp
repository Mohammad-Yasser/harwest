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

const int N = 1e5 + 5;
const int R = 255;
const int A = 'z' - 'a' + 1;
const int Q = 1e3 + 5;

int nxt[N][A];
string s;

void buildNxt() {
  for (int i = 0; i < A; ++i) {
    nxt[s.size()][i] = nxt[s.size() + 1][i] = s.size();
  }
  for (int i = s.size() - 1; i >= 0; --i) {
    for (int c = 0; c < A; ++c) {
      nxt[i][c] = nxt[i + 1][c];
    }
    nxt[i][s[i] - 'a'] = i;
  }
}

string rel[4];
int memo[R][R][R];

int solve(int r1, int r2, int r3) {
  if (r1 == 0 && r2 == 0 && r3 == 0) return -1;
  int& res = memo[r1][r2][r3];
  if (res != -1) return res;
  res = s.size();
  if (r1 > 0) {
    res = min(res, nxt[solve(r1 - 1, r2, r3) + 1][rel[1][r1 - 1] - 'a']);
  }
  if (r2 > 0) {
    res = min(res, nxt[solve(r1, r2 - 1, r3) + 1][rel[2][r2 - 1] - 'a']);
  }
  if (r3 > 0) {
    res = min(res, nxt[solve(r1, r2, r3 - 1) + 1][rel[3][r3 - 1] - 'a']);
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

  int n, q;
  cin >> n >> q >> s;

  buildNxt();

  memset(memo, -1, sizeof memo);

  for (int i = 1; i <= q; ++i) {
    char type;
    int r;
    cin >> type >> r;

    if (type == '-') {
      rel[r].pop_back();
    } else {
      char c;
      cin >> c;
      rel[r] += c;
      for (int a = 0; a < R; ++a) {
        for (int b = 0; b < R; ++b) {
          if (r == 1) memo[rel[r].size()][a][b] = -1;
          if (r == 2) memo[a][rel[r].size()][b] = -1;
          if (r == 3) memo[a][b][rel[r].size()] = -1;
        }
      }
    }

    cout
      << (
        solve(rel[1].size(), rel[2].size(), rel[3].size()) < (int)s.size() ?
          "YES" : "NO") << endl;
  }

}
