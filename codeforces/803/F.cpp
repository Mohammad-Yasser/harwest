#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int MOD = round(1e9 + 7);
const int N = 1e5 + 10;

int pw2[N];

void BuildPow2() {
  pw2[0] = 1;
  for (int i = 1; i < N; ++i) {
    pw2[i] = 2LL * pw2[i - 1] % MOD;
  }
}

int cnt_occ[N];
int cnt_multiples[N];

int cnt_factors[N];
bool reduced[N];

void Build() {
  BuildPow2();

  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      cnt_multiples[i] += cnt_occ[j];
    }
  }

  for (int i = 1; i < N; ++i) {
    reduced[i] = true;
    for (int j = 2; j * j <= i; ++j) {
      if (i % (j * j) == 0) {
        reduced[i] = false;
      }
    }

    if (!reduced[i]) continue;

    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        cnt_factors[i] = cnt_factors[i / j] + 1;
        break;
      }
    }
    if (i != 1) {
      cnt_factors[i] = max(cnt_factors[i], 1);
    }
  }
}

int Solve() {
  int sign[2] = { 1, -1 };

  int res = 0;

  for (int i = 1; i < N; ++i) {
    if (!reduced[i]) continue;

    res = (res + (pw2[cnt_multiples[i]] - 1) * sign[cnt_factors[i] & 1]) % MOD;
    res = (res + MOD) % MOD;
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    ++cnt_occ[x];
  }

  Build();

  cout << Solve();

}
