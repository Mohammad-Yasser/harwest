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

const int N = 1e5 + 5;

Long getProduct(const vector<Long>& v) {
  if (v.size() > 32) return -1;
  Long res = 1;
  for (Long x : v) {
    res *= x;
    if (res > 1e10) return -1;
  }
  return res;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int lines;
  cin >> lines;

  vector<Long> all, nonones;
  Long res = 0;
  for (int i = 1; i <= lines; ++i) {
    string s;
    cin >> s;

    if (s == "add") {
      Long val = getProduct(nonones);
      if (val == -1) {
        cout << "OVERFLOW!!!" << endl;
        return 0;
      }
      res += val;
      if (res > (1LL << 32) - 1) {
        cout << "OVERFLOW!!!" << endl;
        return 0;
      }
    }
    if (s == "for") {
      int x;
      cin >> x;
      all.push_back(x);
      if (x != 1) {
        nonones.push_back(x);
      }
    }
    if (s == "end") {
      if (all.back() != 1) {
        nonones.pop_back();
      }
      all.pop_back();
    }
  }

  if (res > (1LL << 32) - 1) {
    cout << "OVERFLOW!!!" << endl;
    return 0;
  }

  cout << res;

}
