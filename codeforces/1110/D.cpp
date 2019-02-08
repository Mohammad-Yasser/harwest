#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/numeric>

using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))

typedef long long Long;

const int N = 1e6 + 5;
const int M = 5;

int memo[N][M][M];
int arr[N + 5];

int solve(int ind, int r1, int r2) {
  if (ind == N - 1) return 0;
  int& res = memo[ind][r1][r2];
  if (res != -1) return res;
  res = 0;

  for (int nxt = 0;
    nxt < 3 && nxt <= arr[ind] - r1
      && nxt <= min(arr[ind + 1] - r2, arr[ind + 2]); ++nxt) {
    res = max(res,
      solve(ind + 1, r2 + nxt, nxt) + nxt + (arr[ind] - r1 - nxt) / 3);
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++arr[x];
  }

  memset(memo, -1, sizeof memo);

  for (int i = N - 1; i >= 0; --i) {
    solve(i, 0, 0);
  }

  cout << solve(0, 0, 0);

}

