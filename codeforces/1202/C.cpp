#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

template <typename T>
void minimize(T& x, T y) {
  x = min(x, y);
}

template <typename T>
void maximize(T& x, T y) {
  x = max(x, y);
}

typedef long long Long;

int get_x(char c) { return (c == 'D') - (c == 'A'); }

int get_y(char c) { return (c == 'S') - (c == 'W'); }

template <typename T, typename U>
struct SegmentTree {
  int S, H;

  T zero;
  vector<T> value;

  U noop;
  vector<bool> dirty;
  vector<U> prop;

  SegmentTree<T, U>(int _S = 1, T _zero = T(), U _noop = U()) {
    zero = _zero, noop = _noop;
    for (S = 1, H = 1; S < _S;) S *= 2, H++;

    value.resize(2 * S, zero);
    dirty.resize(2 * S, false);
    prop.resize(2 * S, noop);
  }

  void set_leaves(vector<T>& leaves) {
    copy(leaves.begin(), leaves.end(), value.begin() + S);

    for (int i = S - 1; i > 0; i--) value[i] = value[2 * i] + value[2 * i + 1];
  }

  void apply(int i, const U& update) {
    value[i] = update(value[i]);
    if (i < S) {
      prop[i] = prop[i] + update;
      dirty[i] = true;
    }
  }

  void rebuild(int i) {
    for (int l = i / 2; l; l /= 2) {
      T combined = value[2 * l] + value[2 * l + 1];
      value[l] = prop[l](combined);
    }
  }

  void propagate(int i) {
    for (int h = H; h > 0; h--) {
      int l = i >> h;

      if (dirty[l]) {
        apply(2 * l, prop[l]);
        apply(2 * l + 1, prop[l]);

        prop[l] = noop;
        dirty[l] = false;
      }
    }
  }

  void upd(int i, int j, const U& update) {
    i += S, j += S;
    propagate(i), propagate(j);

    for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
      if ((l & 1) == 1) apply(l++, update);
      if ((r & 1) == 0) apply(r--, update);
    }

    rebuild(i), rebuild(j);
  }

  T query(int i, int j) {
    i += S, j += S;
    propagate(i), propagate(j);

    T res_left = zero, res_right = zero;
    for (; i <= j; i /= 2, j /= 2) {
      if ((i & 1) == 1) res_left = res_left + value[i++];
      if ((j & 1) == 0) res_right = value[j--] + res_right;
    }
    return res_left + res_right;
  }
};

struct Node {
  int mn_x = 0, mx_x = 0;
  int mn_y = 0, mx_y = 0;

  Node operator+(const Node& right) const {
    Node res = right;
    minimize(res.mn_x, mn_x);
    maximize(res.mx_x, mx_x);
    minimize(res.mn_y, mn_y);
    maximize(res.mx_y, mx_y);
    return res;
  }

  Long area() const {
    int dx = mx_x - mn_x + 1;
    int dy = mx_y - mn_y + 1;
    return 1LL * dx * dy;
  }
};

struct Update {
  int dx = 0, dy = 0;
  Update() {}
  Update(int dx, int dy) : dx(dx), dy(dy) {}
  Update operator+(const Update& right) const {
    Update res = right;
    res.dx += dx;
    res.dy += dy;
    return res;
  }
  Node operator()(const Node& node) const {
    Node res = node;
    res.mn_x += dx;
    res.mx_x += dx;
    res.mn_y += dy;
    res.mx_y += dy;
    return res;
  }
};

SegmentTree<Node, Update> seg_tree;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  string s;
  while (t--) {
    cin >> s;
    seg_tree = SegmentTree<Node, Update>(2 * s.size() + 4);
    for (int i = 0; i < s.size(); ++i) {
      Update update(get_x(s[i]), get_y(s[i]));
      seg_tree.upd(2 * (i + 1), 2 * s.size() + 3, update);
    }
    Long res = seg_tree.query(0, 2 * s.size() + 3).area();
    for (int i = 0; i < s.size(); ++i) {
      seg_tree.upd(2 * i + 1, 2 * s.size() + 3, Update(1, 0));
      minimize(res, seg_tree.query(0, 2 * s.size() + 3).area());
      seg_tree.upd(2 * i + 1, 2 * s.size() + 3, Update(-2, 0));
      minimize(res, seg_tree.query(0, 2 * s.size() + 3).area());
      seg_tree.upd(2 * i + 1, 2 * s.size() + 3, Update(1, 0));
      seg_tree.upd(2 * i + 1, 2 * s.size() + 3, Update(0, 1));
      minimize(res, seg_tree.query(0, 2 * s.size() + 3).area());
      seg_tree.upd(2 * i + 1, 2 * s.size() + 3, Update(0, -2));
      minimize(res, seg_tree.query(0, 2 * s.size() + 3).area());
      seg_tree.upd(2 * i + 1, 2 * s.size() + 3, Update(0, 1));
    }
    cout << res << endl;
  }
  return 0;
}
