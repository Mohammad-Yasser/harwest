#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = 1e5 + 5;

int getDist(const pair<int, int>& a, const pair<int, int>& b) {
  int res = abs(a.first - b.first) + abs(a.second - b.second);
  return res;
}

void print(const pair<int, int>& p) {
  cout << p.first << " " << p.second << endl;
}

void printAllOnPath(const pair<int, int>& a, const pair<int, int>& b) {
  int x = a.first;
  int y = a.second;
  while (x < b.first) {
    cout << x << " " << y << endl;
    ++x;
  }
  while (x > b.first) {
    cout << x << " " << y << endl;
    --x;
  }
  while (y < b.second) {
    cout << x << " " << y << endl;
    ++y;
  }
  while (y > b.second) {
    cout << x << " " << y << endl;
    --y;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  vector<pair<int, int>> pnts(3);
  for (int i = 0; i < 3; ++i) {
    cin >> pnts[i].first >> pnts[i].second;
  }
  sort(pnts.begin(), pnts.end());

  int best_k = getDist(pnts[0], pnts[1]) + getDist(pnts[1], pnts[2]);

  int mn_x = pnts[0].first;
  int mx_x = pnts[2].first;
  int mn_y = pnts[0].second;
  int mx_y = pnts[2].second;
  if (mn_y > mx_y) swap(mn_y, mx_y);

  for (int x = mn_x; x <= mx_x; ++x) {
    for (int y = mn_y; y <= mx_y; ++y) {
      auto intermediate = make_pair(x, y);
      best_k = min(best_k,
        getDist(pnts[0], pnts[2]) + getDist(intermediate, pnts[1]));
    }
  }

  cout << best_k + 1 << endl;
  if (best_k == getDist(pnts[0], pnts[1]) + getDist(pnts[1], pnts[2])) {
    printAllOnPath(pnts[0], pnts[1]);
    printAllOnPath(pnts[1], pnts[2]);
    print(pnts[2]);
    return 0;
  }

  for (int x = mn_x; x <= mx_x; ++x) {
    for (int y = mn_y; y <= mx_y; ++y) {
      auto intermediate = make_pair(x, y);
      if (best_k
        == getDist(pnts[0], pnts[2]) + getDist(intermediate, pnts[1])) {
        printAllOnPath(pnts[0], intermediate);
        printAllOnPath(intermediate, pnts[1]);
        print(pnts[1]);
        printAllOnPath(pnts[2], intermediate);
        return 0;
      }
    }
  }

}
