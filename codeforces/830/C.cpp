#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 103;
const int MX = 1e9 + 5;
const int SqrtMX = 7.5e5;

int heights[N];
int n;
Long k;

Long res = 1;

Long get(Long d) {
  Long res = 0;
  for (int i = 0; i < n; ++i) {
    res += (d - heights[i] % d) % d;
  }
  return res;
}

bool maximize(Long d) {
  if (get(d) <= k) {
    res = max(res, d);
    return true;
  }
  return false;
}

Long bs(Long start, Long end) {
  Long mid, ans = -1;

  while (start <= end) {
    mid = (start + end) / 2;
    if (get(mid) <= k) {
      ans = mid;
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n >> k;

  vector<Long> critical_points;
  critical_points.push_back(SqrtMX);

  for (int i = 0; i < n; ++i) {
    cin >> heights[i];
    for (int j = 1; j < SqrtMX; ++j) {
      if (heights[i] / j < SqrtMX) break;
      critical_points.push_back(heights[i] / j);
    }
  }

  critical_points.push_back(1e13);
  sort(critical_points.begin(), critical_points.end());

  for (Long i = 1; i <= SqrtMX; ++i) {
    maximize(i);
  }

  Long nxt = critical_points.back();

  while (!critical_points.empty()) {
    Long curr = critical_points.back();
    for (Long j = max(1LL, curr - 1); j <= curr + 1; ++j) {
      maximize(j);
    }

    if (res >= curr - 1) {
      res = max(res, bs(curr + 1, nxt - 1));
      break;
    }
    nxt = curr;
    critical_points.pop_back();
  }

  cout << res;

}