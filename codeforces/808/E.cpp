#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 3e5 + 5;
const int W = 4;
vector<Long> costs[W];

int m;

Long Get2(int cnt2, int m) {
  return costs[2][cnt2] + costs[1][m - 2 * cnt2];
}

Long Solve2(int m) {
  int low = 0, high = m / 2 - 1, mid;
  Long ans = Get2(0, m);

  while (low <= high) {

    mid = (low + high) / 2;

    ans = max(ans, Get2(mid, m));
    ans = max(ans, Get2(mid + 1, m));

    if (Get2(mid, m) < Get2(mid + 1, m)) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

Long Solve3(int m) {
  Long res = 0;
  for (int cnt3 = 0; cnt3 <= m / 3; ++cnt3) {
    Long tmp = costs[3][cnt3] + Solve2(m - 3 * cnt3);

    res = max(res, tmp);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n >> m;

  while (n--) {
    int w, c;
    cin >> w >> c;
    costs[w].push_back(c);
  }

  for (int i = 1; i < W; ++i) {
    while (costs[i].size() < N) {
      costs[i].push_back(0);
    }
    sort(costs[i].rbegin(), costs[i].rend());
    costs[i].insert(costs[i].begin(), 0);
    for (int j = 1; j <= N; ++j) {
      costs[i][j] += costs[i][j - 1];
    }
  }

  cout << Solve3(m) << '\n';

}
