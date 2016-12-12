#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;
const int kMax = 1000006;
int n;
int arr[N];
ll sum[N];

set<tuple<int, int, int>> ranges;

auto FindRange(int x) {
  auto it = ranges.upper_bound(make_tuple(x, kMax, kMax));
  return --it;
}

// 0 1 2 3
// 0 2 3 1
/* - sum (2 , 3)
 * - sum[4] + sum[2]
 *
 *
 * 0 1 2 3
 * 0 3 1 2
 * + sum (1 , 2)
 * + sum[3] - sum[1]
 */

ll CalcMove(ll x, int i, int j) {
  if (i >= j) return -x * i + x * j - sum[j] + sum[i];
  return -x * i + x * j - sum[j + 1] + sum[i + 1];
}

bool Larger(int val, int ind, bool rev) {
  auto it = FindRange(val);
  int curr_ind = get<2>(*it);
  return CalcMove(val, !rev * N, ind) > CalcMove(val, !rev * N, curr_ind);
}

int Find(int ind, bool rev) {
  int low = -kMax + 1, high = kMax - 1, mid, ans = 0;
  while (low <= high) {
    mid = (low + high) / 2;
    if (Larger(mid, ind, rev) != rev) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

void Update(int ind, bool rev = false) {
  int x = Find(ind, rev) - rev;
  auto it = FindRange(x);
  int old = get<2>(*it);

  if (!rev) {
    int range_begin = get<0>(*it);

    ranges.erase(it, ranges.end());
    ranges.insert(make_tuple(x, kMax - 1, ind));

    if (x != range_begin) {
      ranges.insert(make_tuple(range_begin, x - 1, old));
    }
  } else {
    int range_end = get<1>(*it);

    ranges.erase(ranges.begin(), ++it);
    ranges.insert(make_tuple(-kMax + 1, x, ind));

    if (x != range_end) {
      ranges.insert(make_tuple(x + 1, range_end, old));
    }
  }
}

ll Calc() {
  ll res = 0;
  for (int i = 1; i <= n; ++i) {
    res += 1LL * i * arr[i];
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    sum[i + 1] = sum[i] + arr[i];
  }
  ll ans = 0;

  ranges.insert(make_tuple(-kMax + 1, kMax - 1, 1));



  for (int i = 1; i <= n; ++i) {
    Update(i);
    int ind = get<2>(*FindRange(arr[i]));
    ans = max(ans, CalcMove(arr[i], i, ind));
  }

  ranges.clear();
  ranges.insert(make_tuple(-kMax + 1, kMax - 1, n));

  for (int i = n; i >= 1; --i) {
    Update(i, true);
    int ind = get<2>(*FindRange(arr[i]));
    ans = max(ans, CalcMove(arr[i], i, ind));
  }

  ans += Calc();

  cout << ans << endl;

}
