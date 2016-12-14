#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 25;
const int MOD = 1000000007;

int a[N];
int unwanted[2];
int n;

unordered_map<int, vector<int>> pos_sum[2];

int fact[N];

void InitFact() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = 1LL * fact[i - 1] * i % MOD;
  }
}

template<class T> inline void hash_combine(std::size_t & seed, const T & v) {
  std::hash<T> hasher;
  seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
namespace std {
template<typename S, typename T> struct hash<pair<S, T>> {
  inline size_t operator()(const pair<S, T> & v) const {
    size_t seed = 0;
    ::hash_combine(seed, v.first);
    ::hash_combine(seed, v.second);
    return seed;
  }
};
}

unordered_map<pair<int, int>, unordered_map<pair<int, int>, int>> mp[2];

void GenStates(int ind, int last, int sum1, int sum2, int cnt1, int cnt2,
  int map_ind) {
  if (max(sum1, sum2) > 1e9) return;
  if (ind == last) {
    ++mp[map_ind][make_pair(sum1, sum2)][make_pair(cnt1, cnt2)];
    return;
  }

  GenStates(ind + 1, last, sum1, sum2, cnt1, cnt2, map_ind);
  GenStates(ind + 1, last, sum1 + a[ind], sum2, cnt1 + 1, cnt2, map_ind);
  GenStates(ind + 1, last, sum1, sum2 + a[ind], cnt1, cnt2 + 1, map_ind);
}

void GenMasks(int mask, int ind, int last, int sum, int map_ind) {
  if (sum > 1e9) {
    return;
  }
  if (ind == last) {
    pos_sum[map_ind][sum].push_back(__builtin_popcount(mask));
    return;
  }

  GenMasks(mask, ind + 1, last, sum, map_ind);
  GenMasks(mask | (1 << ind), ind + 1, last, sum + a[ind], map_ind);
}

int GetWays(int sum) {
  int res = 0;
  for (auto v1 : pos_sum[0]) {
    for (auto cnt1 : v1.second)
      for (auto cnt2 : pos_sum[1][sum - v1.first]) {
        res = (res + 1LL * fact[cnt1 + cnt2] * fact[n - cnt1 - cnt2]) % MOD;
      }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  InitFact();

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int k;
  cin >> k;

  if (k == 0) {
    cout << fact[n];
    return 0;
  }

  for (int i = 0; i < k; ++i) {
    cin >> unwanted[i];
  }

  if (k == 1) {
    k = 2;
    unwanted[1] = unwanted[0];
  }

  sort(unwanted, unwanted + 2);

  GenMasks(0, 0, n / 2, 0, 0);
  GenMasks(0, n / 2, n, 0, 1);

  int ans = fact[n];
  ans = (ans + MOD - GetWays(unwanted[0])) % MOD;
  ans = (ans + MOD - GetWays(unwanted[1])) % MOD;

  GenStates(0, n / 2, 0, 0, 0, 0, 0);
  GenStates(n / 2, n, 0, 0, 0, 0, 1);

//  for (auto &p1 : mp[1]) {
//    cout << p1.first.first << ' ' << p1.first.second << endl;
//  }
//  cout << "------------\n";

  for (auto& p1 : mp[0]) {
    auto& v2 = mp[1][make_pair(unwanted[0] - p1.first.first,
      unwanted[1] - unwanted[0] - p1.first.second)];
    for (auto &c1 : p1.second) {
      for (auto &c2 : v2) {
        int d1 = c1.first.first + c2.first.first;
        int d2 = c1.first.second + c2.first.second;
        int d3 = n - d1 - d2;
        ll tmp = 1LL * c1.second * c2.second % MOD;
        tmp = tmp * fact[d1] % MOD;
        tmp = tmp * fact[d2] % MOD;
        tmp = tmp * fact[d3] % MOD;
        ans = (ans + tmp) % MOD;
      }
    }
  }

  cout << ans;
}
