#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef unsigned long long Long;

const int N = 16;
const int OO = INT_MAX / 2;
int r[N];
int b[N];
bool is_red[N];

int cnt_r[1 << N];
int cnt_b[1 << N];
int n;

void buildCnt(int mask) {
  for (int i = 0; i < n; ++i) {
    if ((mask >> i) & 1) {
      if (is_red[i]) {
        ++cnt_r[mask];
      } else {
        ++cnt_b[mask];
      }
    }
  }
}

int memo[1 << N][N * (N - 1) / 2 + 1];
int min_x[1 << N];
int max_x[1 << N];

int solve(int mask, int x) {
  if (x < min_x[mask]) return OO;
  if (mask == (1 << n) - 1) return 0;
  int& res = memo[mask][x - min_x[mask]];
  if (res != -1) return res;
  res = OO;

  for (int i = 0; i < n; ++i) {
    if ((mask >> i) & 1) continue;
    res = min(res,
      max(b[i] - cnt_b[mask], 0)
        + solve(mask | (1 << i), x - max(r[i] - cnt_r[mask], 0)));
  }

//  cout << bitset<2>(mask).to_string() << " " << x << " " << res << endl;
  return res;
}

void buildX(int mask) {
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if ((mask >> i) & 1) continue;
    min_x[mask] += r[i] - cnt - popCnt(mask);
    max_x[mask] += r[i];
    ++cnt;
  }
}

void build() {
  memset(min_x, 0, sizeof min_x);
  memset(max_x, 0, sizeof max_x);
  memset(memo, -1, sizeof memo);

  for (int i = 0; i < (1 << n); ++i) {
    buildCnt(i);
    buildX(i);
  }

}

int solve() {
  build();
  int res = OO;
  for (int x = min_x[0]; x <= max_x[0]; ++x) {
    res = min(res, max(x, solve(0, x)));
  }
  return n + res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n;

  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c >> r[i] >> b[i];
    is_red[i] = (c == 'R');
  }

  cout << solve() << endl;

}

