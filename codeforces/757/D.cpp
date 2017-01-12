#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Component;

const int MOD = 1000000007;
const int kMax = 22;
const int N = 75;

map<int, int> memo[N];
int first_one[N];

bool valid_mask[1 << kMax];
int need_cnt[1 << kMax];

string poke;
int n;

int GetLargestBit(int x) {
  int last_one = 0;
  for (int i = 0; i < 32; ++i) {
    if ((x >> i) & 1) last_one = i;
  }
  return last_one + 1;
}

int GetCnt(int mask) {
  int last_one = GetLargestBit(mask);
  int res = 0;

  for (int i = 1; i < last_one; ++i) {
    if ((mask >> i) & 1) continue;
    res += GetLargestBit(i);
  }

  return res;
}

void BuildNeedCnt() {
  for (int i = 0; i < (1 << kMax); ++i) {
    need_cnt[i] = GetCnt(i);
  }
}

int Solve(int ind, int mask) {
  if (ind == n) {
    return valid_mask[mask];
  }
  if (poke[ind] != 1) {
    return Solve(first_one[ind], mask);
  }

  if (n - ind < need_cnt[mask]) {
    return 0;
  }

  if (memo[ind].count(mask)) {
    return memo[ind][mask];
  }

  int res = valid_mask[mask];

  int curr = 0;

  for (int i = ind; i < min(n, ind + 5); ++i) {
    curr = curr * 2 + poke[i];
    if (curr >= kMax) break;
    res = (res + Solve(i + 1, mask | (1 << curr))) % MOD;
  }

  return memo[ind][mask] = res;
}

void BuildFirstOne() {
  for (int i = 0; i < n; ++i) {
    first_one[i] = n;
    for (int j = i; j < n; ++j) {
      if (poke[j] == 1) {
        first_one[i] = j;
        break;
      }
    }
  }
}

void BuildValidMask() {
  for (int i = 2; i < kMax; ++i) {
    valid_mask[(1 << i) - 2] = true;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  freopen("wa.txt", "w", stdout);
#endif

  cin >> n >> poke;
  for (char& c : poke) {
    c -= '0';
  }
  BuildValidMask();
  BuildFirstOne();
  BuildNeedCnt();

  int res = 0;

  for (int i = 0; i < n; ++i) {
    res = (res + Solve(i, 0)) % MOD;
  }

  cout << res;

}
