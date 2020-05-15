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

const int N = 1e5 + 5;
const int OO = INT_MAX / 2;

template <typename T, typename U>
struct SegmentTree {
  int S, H;

  T zero;
  vector<T> value;

  U noop;
  vector<bool> dirty;
  vector<U> prop;

  void init(int _S = N, T _zero = T(), U _noop = U()) {
    zero = _zero, noop = _noop;
    for (S = 1, H = 1; S < _S;) S *= 2, H++;
    value.clear(), dirty.clear(), prop.clear();
    value.resize(2 * S, zero);
    dirty.resize(2 * S, false);
    prop.resize(2 * S, noop);
  }

  SegmentTree<T, U>(int _S = N, T _zero = T(), U _noop = U()) {
    init(_S, _zero, _noop);
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
  int cost = OO;
  Node operator+(const Node& right) const {
    Node res = right;
    res.cost = min(res.cost, cost);
    return res;
  }
};

// The default value must not change an update when merged.
// I.e. any_update + Update() must be = any_update.
struct Update {
  int val = OO;
  Update(int val = OO) : val(val) {}
  Update operator+(const Update& right) const {
    Update res = right;
    res.val = min(res.val, val);
    return res;
  }
  Node operator()(const Node& node) const {
    Node res = node;
    res.cost = min(res.cost, val);
    return res;
  }
};

SegmentTree<Node, Update> seg_tree[2][2];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, k;
  cin >> n >> k;

  int prev = 0;
  seg_tree[0][0].upd(0, 0, Update(0));

  vector<pair<int, int>> intervals;
  for (int i = 0; i < k; ++i) {
    int l, r;
    cin >> l >> r;
    intervals.emplace_back(l, l);
    if (l != r) intervals.emplace_back(l + 1, r);
  }
  intervals.emplace_back(2 * n, 2 * n);

  bool curr = 0;
  for (auto& interval : intervals) {
    bool nxt = !curr;

    seg_tree[nxt][0].init(), seg_tree[nxt][1].init();

    int l, r;
    tie(l, r) = interval;
    int diff = l - prev;
    prev = r;

    for (int side = 0; side < 2; ++side) {  // current side
      for (int curr_time = 0; curr_time <= n;
           ++curr_time) {  // time taken on side 0.
        int curr_flips = seg_tree[curr][side].query(curr_time, curr_time).cost;
        if (curr_flips == OO) continue;

        // No flips
        int nxt_time = curr_time + diff + r - l;
        if (side == 1) {
          nxt_time = curr_time;
        }
        if (nxt_time <= n) {
          seg_tree[nxt][side].upd(nxt_time, nxt_time, Update(curr_flips));
        }

        // One flip
        if (side == 0) {
          int nxt_time_l = curr_time + diff;
          int nxt_time_r = curr_time + diff + r - l;
          nxt_time_r = min(nxt_time_r, n);
          if (nxt_time_l > n) goto nxt;
          seg_tree[nxt][1].upd(nxt_time_l, nxt_time_r, Update(curr_flips + 1));
        nxt:;
        } else {
          int nxt_time_l = curr_time;
          int nxt_time_r = curr_time + r - l;
          nxt_time_r = min(nxt_time_r, n);
          seg_tree[nxt][0].upd(nxt_time_l, nxt_time_r, Update(curr_flips + 1));
        }
      }
    }
    curr = nxt;
  }

  int res = seg_tree[curr][0].query(n, n).cost;
  res = min(res, seg_tree[curr][1].query(n, n).cost);

  if (res == OO) {
    cout << "Hungry" << endl;
  } else {
    cout << "Full" << endl;
    cout << res << endl;
  }

  return 0;
}