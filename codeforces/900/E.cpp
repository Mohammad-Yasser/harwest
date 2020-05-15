#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

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
typedef double Double;

const int N = 1e5 + 5;

int m;

struct Result {
  int occ;
  int cost;
  bool operator<(const Result& other) const {
    return make_tuple(-occ, cost) < make_tuple(-other.occ, other.cost);
  }
  Result operator+(const Result& other) const {
    Result res = other;
    res.occ += occ;
    res.cost += cost;
    return res;
  }
  Result(int occ = 0, int cost = 0) : occ(occ), cost(cost) {}
};

Result memo[N];
int last[N][2];
int cnt_q[N];

string s;
int n;

Result solve(int ind) {
  if (ind + m > n) return Result(0, 0);
  auto& res = memo[ind];
  if (res.occ != -1) return res;
  res = solve(ind + 1);
  if (last[ind][0] >= ind + m && s[ind] != 'b') {
    res = min(res, Result(1, cnt_q[ind + m] - cnt_q[ind]) + solve(ind + m));
  }
  return res;
}

int getPos(const vector<int>& v, int val) { return *lower_bound(all(v), val); }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n >> s >> m;

  last[n][0] = last[n][1] = n;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 2; ++j) {
      if (s[i] != '?' && s[i] != "ab"[j]) {
        last[i][j] = i;
      } else {
        last[i][j] = last[i + 1][!j];
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    cnt_q[i] = cnt_q[i - 1] + (s[i - 1] == '?');
  }

  memset(memo, -1, sizeof memo);

  cout << solve(0).cost << endl;

  return 0;
}