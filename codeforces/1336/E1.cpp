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

bool isSet(Long n, int b) { return (n >> b) & 1LL; }

void printRow(int x) { cout << bitset<5>(x).to_string() << endl; }

void printMat(const vector<Long>& mat) {
  for (auto& x : mat) {
    printRow(x);
  }
}

vector<Long> getRREF(const vector<Long>& mat) {
  vector<Long> res = mat;
  int rank = 0;
  for (int row = 0, col = 63; row < res.size() && col >= 0; --col) {
    for (int i = row; i < res.size(); ++i) {
      if (isSet(res[i], col)) {
        swap(res[row], res[i]);
        break;
      }
    }
    if (!isSet(res[row], col)) continue;
    ++rank;
    for (int i = 0; i < res.size(); ++i) {
      if (i == row) continue;
      if (isSet(res[i], col)) {
        res[i] ^= res[row];
      }
    }

    ++row;
  }

  // Remove 0s.
  while (res.back() == 0) {
    res.pop_back();
  }
  return res;
}

int getRank(const vector<Long>& mat) {
  int res = 0;
  for (auto& x : mat) {
    res += (x != 0);
  }
  return res;
}

const int N = 17;
const int MOD = 998244353;
int memo[N + 1][N][1 << N];
int pop_cnt[1 << N];
int lg[1 << N];

int solve(int cnt, int ind, int mask, const vector<Long>& basis) {
  if (ind == basis.size()) return pop_cnt[mask] == cnt;
  int lg_curr_basis = lg[basis[ind]];
  int filtered_mask = mask & ((1 << (lg_curr_basis + 1)) - 1);
  cnt -= pop_cnt[mask ^ filtered_mask];
  mask = filtered_mask;
  if (cnt < 0 || cnt > 1 + lg_curr_basis) return 0;
  int& res = memo[cnt][ind][mask];
  if (res != -1) return res;
  res = solve(cnt, ind + 1, mask, basis);
  res = (res + solve(cnt, ind + 1, mask ^ basis[ind], basis)) % MOD;
  return res;
}

int fastPower(int base, int p) {
  if (p == 0) return 1;
  int res = fastPower(base, p / 2);
  res = 1LL * res * res % MOD;
  if (p & 1) {
    res = 1LL * res * base % MOD;
  }
  return res;
}

pair<vector<Long>, vector<Long>> divideBasis(const vector<Long>& basis) {
  auto left_basis = basis;
  vector<Long> right_basis;
  while (!left_basis.empty() && left_basis.back() < (1 << N)) {
    right_basis.emplace_back(left_basis.back());
    left_basis.pop_back();
  }
  reverse(right_basis.begin(), right_basis.end());
  return make_pair(left_basis, right_basis);
}

void init() {
  lg[0] = -1;
  for (int i = 1; i < (1 << N); ++i) {
    pop_cnt[i] = 1 + pop_cnt[i ^ (i & -i)];
    lg[i] = lg[i - 1] + (i == (i & -i));
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  init();
  int n, m;
  cin >> n >> m;
  vector<Long> arr(n);

  for (auto& x : arr) {
    cin >> x;
  }

  auto basis = getRREF(arr);
  vector<Long> left_basis, right_basis;
  tie(left_basis, right_basis) = divideBasis(basis);

  int left_cnt = left_basis.size();

  vector<Long> left_masks;
  left_masks.reserve(1 << left_cnt);
  left_masks.emplace_back(0);
  for (auto basis : left_basis) {
    int sz = left_masks.size();
    for (int j = 0; j < sz; ++j) {
      left_masks.emplace_back(left_masks[j] ^ basis);
    }
  }
  memset(memo, -1, sizeof memo);
  for (int i = 0; i <= m; ++i) {
    int res = 0;
    for (auto& left_mask : left_masks) {
      int right_mask = (left_mask & ((1LL << N) - 1));
      res = (res + solve(i - popCnt(left_mask ^ right_mask), 0, right_mask,
                         right_basis)) %
            MOD;
    }
    res = 1LL * res * fastPower(2, n - basis.size()) % MOD;
    cout << res << " ";
  }

  return 0;
}