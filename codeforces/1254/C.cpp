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

const int N = 1003;
Long area[N];

vector<int> solve(const vector<int>& v) {
  if (v.empty()) return {};
  vector<int> res;

  int mx = v[0];
  for (int x : v) {
    if (area[x] > area[mx]) {
      mx = x;
    }
  }

  vector<int> first, second;

  for (int x : v) {
    if (x == mx) continue;
    cout << "2 " << x << " 1 " << mx << endl;
    int ans;
    cin >> ans;
    if (ans == -1) {
      first.push_back(x);
    } else {
      second.push_back(x);
    }
  }

  sort(first.begin(), first.end(), [](int i , int j) {
    return area[i] < area[j];
  });

  sort(second.begin(), second.end(), [](int i , int j) {
    return area[i] > area[j];
  });

  for (int x : first) {
    res.push_back(x);
  }

  res.push_back(mx);

  for (int x : second) {
    res.push_back(x);
  }

  return res;
}

int main() {
//  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
//  freopen("test.in", "r", stdin);
#else
#endif

  int n;
  cin >> n;

  vector<int> first, second;

  for (int i = 3; i <= n; ++i) {
    cout << "1 1 2 " << i << endl;
    cin >> area[i];
    cout << "2 " << i << " 1 2" << endl;
    int x;
    cin >> x;
    if (x == -1) {
      first.push_back(i);
    } else {
      second.push_back(i);
    }
  }

  first = solve(first);
  second = solve(second);

  cout << "0 ";
  cout << 1 << " ";
  for (int x : first) {
    cout << x << " ";
  }
  cout << 2 << " ";
  for (int x : second) {
    cout << x << " ";
  }
  cout << endl;
}