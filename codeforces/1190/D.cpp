#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

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
const int N = 1e6;

template <class INT, int nLeaves>
struct BIT {
  const int kMaxSize = 1 << (int)ceil(log2(nLeaves + 1e-9));
  vector<INT> arr;
  INT size = 0;

  BIT() { arr.resize(kMaxSize, 0); }

  INT get(int i) {
    i++;
    INT r = 0;
    while (i) {
      r += arr[i - 1];
      i -= i & -i;
    }
    return r;
  }

  INT get(int l, int r) {
    if (r < l) return 0;
    if (l == 0) return get(r);
    return get(r) - get(l - 1);
  }

  void add(int i, INT val = 1) {
    size += val;
    i++;
    while (i <= kMaxSize) {
      arr[i - 1] += val;
      i += i & -i;
    }
  }

  // Finds element at index ind.
  int find(INT ind) {
    int s = 0;
    int m = kMaxSize >> 1;
    while (m) {
      if (arr[s + m - 1] < ind) ind -= arr[(s += m) - 1];
      m >>= 1;
    }
    return s;
  }
};

BIT<int, N> bit;

vector<pair<int, int>> compress(const vector<pair<int, int>>& v) {
  map<int, int> mp;
  for (auto& p : v) {
    mp[p.first];
    mp[p.second];
  }
  int curr = 0;
  for (auto& p : mp) {
    p.second = ++curr;
  }
  auto res = v;
  for (auto& p : res) {
    p.first = mp[p.first];
    p.second = mp[p.second];
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

  int n;
  cin >> n;

  vector<pair<int, int>> v(n);

  for (auto& p : v) {
    cin >> p.first >> p.second;
  }

  v = compress(v);

  map<int, vector<int>> mp;

  for (auto& p : v) {
    mp[p.second].emplace_back(p.first);
  }

  Long res = 0;
  int cnt_xs = 0;
  for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
    auto& v = it->second;
    sort(v.begin(), v.end());
    for (int x : v) {
      if (bit.get(x, x) == 0) {
        bit.add(x);
        ++cnt_xs;
      }
    }
    res += 1LL * cnt_xs * (cnt_xs + 1) / 2;
    int prev_x = 0;
    for (int x : v) {
      int left = bit.get(prev_x, x - 1);
      res -= 1LL * left * (left + 1) / 2;
      prev_x = x + 1;
    }
    int right = bit.get(prev_x, N - 1);
    res -= 1LL * right * (right + 1) / 2;
  }

  cout << res << endl;

  return 0;
}
