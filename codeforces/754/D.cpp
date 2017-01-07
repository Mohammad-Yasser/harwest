#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 300005;
const int kMax = 1e9;

tuple<int, int, int> coupons[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("wa.txt", "w", stdout);
#endif

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> get<0>(coupons[i]) >> get<1>(coupons[i]);
    get<2>(coupons[i]) = i + 1;
  }

  sort(coupons, coupons + n);

  pair<int, int> max_range = { -kMax - 1, -kMax - 2 };

  multiset<int> ends;

  for (int i = 0; i < n; ++i) {
    auto& coupon = coupons[i];
    ends.insert(get<1>(coupon));
    if (ends.size() > k) {
      ends.erase(ends.begin());
    }
    if (ends.size() == k
      && *ends.begin() - get<0>(coupon) > max_range.second - max_range.first) {
      max_range = {get<0>(coupon),*ends.begin()};
    }
  }

  cout << max_range.second - max_range.first + 1 << '\n';

  if (max_range.first == -kMax - 1) {
    for (int i = 1; i <= k; ++i) {
      cout << i << ' ';
    }
    return 0;
  }

  for (int i = 0; i < n && k > 0; ++i) {
    if (get<0>(coupons[i]) <= max_range.first
      && max_range.second <= get<1>(coupons[i])) {
      cout << get<2>(coupons[i]) << ' ';
      --k;
    }
  }

}
