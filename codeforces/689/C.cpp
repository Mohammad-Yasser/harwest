#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll GetWays(ll n) {
  ll x = 2, res = 0, tmp;
  while (tmp = n / (x * x * x)) res += n / (x * x * x), ++x;
  return res;
}

inline ll bs(ll n_ways) {
  ll low = 1, high = 1e16, mid, ans;
  while (low <= high) {
    mid = (low + high) / 2;
    if (GetWays(mid) >= n_ways)
      ans = mid, high = mid - 1;
    else
      low = mid + 1;
  }
  if (GetWays(ans) == n_ways) return ans;
  return -1;
}

int main() {
  ll n_ways;
  cin >> n_ways;
  cout << bs(n_ways) << endl;
  return 0;
}
