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
int end_[N];
int cnt_q[N];

string s;
int n;

vector<int> occ[2][2];

Result solve(int ind) {
  if (ind + m > n) return Result(0, 0);
  auto& res = memo[ind];
  if (res.occ != -1) return res;
  res = solve(ind + 1);
  if (end_[ind] >= ind + m && s[ind] != 'b') {
    res = min(res, Result(1, cnt_q[ind + m] - cnt_q[ind]) + solve(ind + m));
  }
  // cout << ind << " " << res.occ << " " << res.cost << " " << end_[ind] <<
  // endl;
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

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'a') {
      occ[0][i & 1].emplace_back(i);
    } else if (s[i] == 'b') {
      occ[1][i & 1].emplace_back(i);
    }
  }

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      occ[i][j].emplace_back(N);
    }
  }
  end_[n] = end_[n + 1] = end_[N] = N;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == 'b') {
      end_[i] = getPos(occ[1][~i & 1], i);
    } else if (s[i] == 'a') {
      end_[i] = getPos(occ[0][~i & 1], i);
      int nxt_b = getPos(occ[1][i & 1], i);
      end_[i] = min(end_[i], nxt_b);
      nxt_b = min(nxt_b, getPos(occ[1][~i & 1], i));
      end_[i] = min(end_[i], end_[i + 2]);
      end_[i] = min(end_[i], end_[nxt_b]);
    } else {
      int nxt_a = getPos(occ[0][0], i);
      nxt_a = min(nxt_a, getPos(occ[0][1], i));
      if (nxt_a == N) {
        end_[i] = N;
      } else if ((nxt_a & 1) != (i & 1)) {
        end_[i] = nxt_a;
      } else {
        end_[i] = end_[nxt_a];
      }
      int nxt_b = getPos(occ[1][i & 1], i);
      end_[i] = min(end_[i], nxt_b);
      nxt_b = min(nxt_b, getPos(occ[1][~i & 1], i));
      end_[i] = min(end_[i], end_[nxt_b]);
    }
  }

  for (int i = 1; i <= n; ++i) {
    cnt_q[i] = cnt_q[i - 1] + (s[i - 1] == '?');
  }

  memset(memo, -1, sizeof memo);

  cout << solve(0).cost << endl;

  return 0;
}