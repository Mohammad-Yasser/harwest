#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
typedef long long Long;
typedef double Double;

template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}

template <class T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

const int N = 2003;
const int A = 4 * N;
const int MOD = 1000000007;
int memo[N][A];

int n;
int arr[N];
int power(int base, int p) {
  if (p == 0) return 1;
  int res = power(base, p / 2);
  res = 1LL * res * res % MOD;
  if (p & 1) {
    res = 1LL * res * base % MOD;
  }
  return res;
}
int k;

int count(int ind, int curr_sum) {
  if (curr_sum >= k) {
    return 0;
  }
  if (ind == n) return 1;
  int& res = memo[ind][curr_sum];
  if (res != -1) return res;
  res = 0;
  for (int val = 2; val <= 4; val += 2) {
    if (arr[ind] != 0 && arr[ind] != val) continue;
    if (val == 4 && (curr_sum / 2) % 2 == 1) {
      res = (res + count(ind + 1, val)) % MOD;
    } else {
      res = (res + count(ind + 1, curr_sum + val)) % MOD;
    }
  }
  // cout << ind << " " << curr_sum << " " << res << endl;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  memset(memo, -1, sizeof memo);
  cin >> n >> k;
  k = (1 << k);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  int total_ways = power(2, count(arr, arr + n, 0));
  cout << (total_ways - count(0, 0) + MOD) % MOD << endl;

  return 0;
}