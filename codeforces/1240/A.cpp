#ifndef Local
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

// gp_hash_table<int, int> table;

Long getC(const vector<Long>& prices, int x, int a, int y, int b, int n) {
  Long c = 1LL * a * b / __gcd(a, b);
  int cnt_c = n / c;
  int cnt_b = n / b - cnt_c;
  int cnt_a = n / a - cnt_c;
  Long res = prices[cnt_c] * (x + y);
  res += (prices[cnt_b + cnt_c] - prices[cnt_c]) * y;
  res += (prices[cnt_b + cnt_c + cnt_a] - prices[cnt_b + cnt_c]) * x;
  return res;
}

int solve(const vector<Long>& prices, int x, int a, int y, int b, Long k) {
  int low = 1, high = prices.size() - 1, ans = prices.size() + 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (getC(prices, x, a, y, b, mid) >= k) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (ans == prices.size() + 1) return -1;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int q;
  cin >> q;

  while (q--) {
    int n;
    cin >> n;
    vector<Long> prices(n);
    for (Long& price : prices) {
      cin >> price;
      price /= 100;
    }
    sort(prices.rbegin(), prices.rend());
    prices.insert(prices.begin(), 0);
    for (int i = 1; i < prices.size(); ++i) {
      prices[i] += prices[i - 1];
    }
    int x, a, y, b;
    Long k;
    cin >> x >> a >> y >> b >> k;
    if (y < x) {
      swap(x, y);
      swap(a, b);
    }
    cout << solve(prices, x , a , y , b , k) << endl;
  }

}
