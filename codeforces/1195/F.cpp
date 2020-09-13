#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse4,sse4.2,popcnt,abm,mmx,avx")
#endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
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
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

struct Point {
  int x, y;
  Point operator-(const Point& other) const {
    Point res = *this;
    res.x -= other.x, res.y -= other.y;
    return res;
  }
  Point normalize() const {
    int sign_x = (x >= 0 ? 1 : -1);
    int sign_y = (y >= 0 ? 1 : -1);
    int g = __gcd(abs(x), abs(y));
    Point res = Point(abs(x), abs(y));
    res.x /= g, res.y /= g;
    res.x *= sign_x, res.y *= sign_y;
    return res;
  }
  Point(int x = 0, int y = 0) : x(x), y(y) {}
  bool operator==(const Point& other) const {
    return x == other.x && y == other.y;
  }
};

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int RANDOM =
    chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {  // To use most bits rather than just the lowest ones:
  const uint64_t C = Long(4e18 * acos(0)) | 71;  // large odd number
  Long operator()(const Point& p) const { return (p.x) * C + (p.y); }
};

__gnu_pbds::gp_hash_table<Point, int, chash> ht({}, {}, {}, {}, {1 << 16});

template <class INT, int nLeaves>
struct BIT {
  const int kMaxSize = 1 << (int)ceil(log2(nLeaves + 1e-9));
  vector<INT> arr;
  INT size = 0;

  BIT() { arr.resize(kMaxSize); }

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
};
const int N = 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  vector<vector<Point>> polys(n);
  for (auto& poly : polys) {
    int k;
    cin >> k;
    poly.resize(k);
    for (auto& p : poly) {
      int x, y;
      cin >> x >> y;
      p = Point(x, y);
    }
  }

  int q;
  cin >> q;
  vector<vector<int>> queries(n);
  vector<int> res(q), l(q);

  for (int i = 0; i < q; ++i) {
    int r;
    cin >> l[i] >> r;
    --l[i], --r;
    queries[r].emplace_back(i);
  }

  BIT<int, N> bit;

  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < sz(polys[i]); ++k) {
      int j = (k + 1) % sz(polys[i]);
      auto v = (polys[i][j] - polys[i][k]).normalize();
      if (ht.find(v) == end(ht)) {
        bit.add(i);
        ht[v] = i;
      } else {
        bit.add(ht[v], -1);
        ht[v] = i;
        bit.add(i);
      }
    }

    for (int q : queries[i]) {
      res[q] = bit.get(l[q], i);
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << res[i] << endl;
  }

  return 0;
}