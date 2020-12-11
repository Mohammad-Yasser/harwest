#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("popcnt,abm,mmx,avx2")
#endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define rep(i, l, r) for (int i = l; i < r; ++i)
typedef long long Long;
typedef double Double;

template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int RANDOM =
    chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {  // To use most bits rather than just the lowest ones:
  const uint64_t C = Long(4e18 * acos(0)) | 71;  // large odd number
  Long operator()(Long x) const { return __builtin_bswap64((x ^ RANDOM) * C); }
};
__gnu_pbds::gp_hash_table<Long, bool, chash> ht({}, {}, {}, {}, {1 << 16});

void go(const vector<int>& v, int l, int r) {
  Long sum = accumulate(begin(v) + l, begin(v) + r + 1, 0LL);
  ht[sum] = true;
  if (l == r) return;
  int mid = l;
  while (mid + 1 <= r && v[mid + 1] <= (v[l] + v[r]) / 2) {
    ++mid;
  }
  if (mid == r) return;
  go(v, l, mid);
  go(v, mid + 1, r);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif
  int t;
  cin >> t;
  while (t--) {
    ht.clear();
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    cin >> v;
    sort(all(v));
    go(v, 0, sz(v) - 1);
    while (q--) {
      int s;
      cin >> s;
      if (ht.find(s) == ht.end()) {
        cout << "No" << endl;
      } else {
        cout << "Yes" << endl;
      }
    }
  }
  return 0;
}
