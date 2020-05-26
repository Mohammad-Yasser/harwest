#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
typedef long long Long;
typedef double Double;

int n;
Long x;
Long solve(const vector<int>& d, bool rev) {
  Long cnt_days = 0;
  int curr_month = 0;
  int nxt_day = 0;
  Long curr_sum = 0;
  Long res = 0;

  for (int i = 0; i < n; ++i) {
    while (cnt_days < x) {
      if (x - cnt_days >= d[curr_month] - nxt_day) {
        int tmp = d[curr_month] - nxt_day;
        cnt_days += tmp;
        if (rev) {
          curr_sum += 1LL * tmp * (tmp + 1) / 2;
        } else {
          curr_sum += 1LL * tmp * (nxt_day + 1 + d[curr_month]) / 2;
        }
        ++curr_month;
        nxt_day = 0;
        continue;
      }
      int tmp = x - cnt_days;
      cnt_days += tmp;
      if (rev) {
        curr_sum +=
            1LL * tmp *
            ((d[curr_month] - nxt_day) + (d[curr_month] - nxt_day - tmp + 1)) /
            2;
      } else {
        curr_sum += 1LL * tmp * (2 * nxt_day + 1 + tmp) / 2;
      }
      nxt_day += tmp;
    }
    // cout << i << " " << nxt_day << " " << curr_month << " " << curr_sum <<
    // endl;
    res = max(res, curr_sum);
    cnt_days -= d[i];
    curr_sum -= 1LL * d[i] * (d[i] + 1) / 2;
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

  cin >> n >> x;
  vector<int> d(2 * n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
    d[i + n] = d[i];
  }
  Long res = 0;
  res = max(res, solve(d, false));
  reverse(all(d));
  res = max(res, solve(d, true));
  cout << res << endl;

  return 0;
}