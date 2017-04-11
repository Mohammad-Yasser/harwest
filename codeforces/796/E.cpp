#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

const int N = 1e3 + 3;
const int K = 51;

short memo[N][N][K][2];
int k;

bool solved[N][2];

short cnt[N][2];
short intersections[N][N];

void Build() {
  for (int i = 0; i < N; ++i) {
    for (int j = i; j < min(N, i + k); ++j) {
      for (int z = 0; z < 2; ++z) {
        cnt[i][z] += solved[j][z];
      }
      intersections[i][j + 1] = intersections[i][j]
        + (solved[j][0] && solved[j][1]);
    }
  }
}

short Solve(int rem, int ind, int last_q, bool last_p) {
  if (rem == 0 || ind >= N) return 0;
  last_q = max(last_q, ind);
  last_q = min(last_q, N);

  short& res = memo[rem][ind][last_q - ind][last_p];

  if (res != -1) return res;

  res = Solve(rem, ind + 1, last_q, last_p);

  if (last_p || last_q == ind) {
    res = max(res,
      short(
        Solve(rem - 1, max(ind + 1, last_q), ind + k, false) + cnt[ind][false]
          - intersections[ind][last_q]));
  }

  if (!last_p || last_q == ind) {
    res = max(res,
      short(
        Solve(rem - 1, max(ind + 1, last_q), ind + k, true) + cnt[ind][true]
          - intersections[ind][last_q]));
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  memset(memo, -1, sizeof memo);

  int n, p;

  cin >> n >> p >> k;

  for (int i = 0; i < 2; ++i) {
    int tmp;
    cin >> tmp;
    while (tmp--) {
      int id;
      cin >> id;
      solved[id][i] = true;
    }
  }

  Build();

  int res = Solve(p, 0, 0, 0);

  cout << res << '\n';

}
