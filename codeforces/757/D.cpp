#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;
const int kMax = 20;
const int N = 75;

int memo[N][1 << kMax];
int first_one[N];
int need_cnt[1 << kMax];

string poke;
int n;

bool ValidMask(int mask) {
  return mask != 0 && (mask & (mask + 1)) == 0;
}

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
    return ValidMask(mask);
  }

  if (poke[ind] != 1) {
    return Solve(first_one[ind], mask);
  }
  if (n - ind < need_cnt[mask]) {
    return 0;
  }
  int& res = memo[ind][mask];
  if (res != -1) {
    return res;
  }

  res = ValidMask(mask);

  int curr = 0;

  for (int i = ind; i < min(n, ind + 5); ++i) {
    curr = curr * 2 + poke[i];
    if (curr > kMax) break;
    res = (res + Solve(i + 1, mask | (1 << (curr - 1)))) % MOD;
  }

  return res;
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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("wa.txt", "w", stdout);
#endif

  memset(memo, -1, sizeof memo);

  cin >> n >> poke;
  for (char& c : poke) {
    c -= '0';
  }
  BuildFirstOne();

  int res = 0;

  for (int i = 0; i < n; ++i) {
    res = (res + Solve(i, 0)) % MOD;
  }

  cout << res;

}
