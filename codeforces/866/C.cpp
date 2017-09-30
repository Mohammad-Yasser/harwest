#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef long double Double;

const int N = 51;
const int S = N * 101;

Double memo[N][S];

int T;
int n;

Double F;

int fast[N];
int slow[N];
Double p[N];

Double solve(int ind, int t) {
  if (t < 0) return F;
  if (ind == n) return 0;

  auto& res = memo[ind][t];

  if (res == res) return res;

  res = F;

  if (ind == 0) {
    res = 1e50;
  }

  res = min(res,
    p[ind] * (fast[ind] + solve(ind + 1, t - fast[ind]))
      + (1 - p[ind]) * (slow[ind] + solve(ind + 1, t - slow[ind])));

  return res;
}

Double bs() {
  memset(memo, -1, sizeof memo);
  Double high = 1e15;
  F = high;

  Double low = 0;

  for (int i = 0; i < 100; ++i) {
    F = (low + high) / 2;
    memset(memo, -1, sizeof memo);


    if (solve(0, T) > F) {
      low = F;
    } else {
      high = F;
    }
  }
  return F;
}


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n >> T;

  for (int i = 0; i < n; ++i) {
    cin >> fast[i] >> slow[i] >> p[i];
    p[i] /= 100;
  }

  cout << fixed << setprecision(10) << bs() << endl;
}
