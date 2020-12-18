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

const int N = 1e5 + 5;

template <class INT, int kMaxSize>
struct BIT {
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

  void addRange(int l, int r) {
    add(r + 1, -1);
    add(l, 1);
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
  int lower_bound(int x) { return find(get(x - 1) + 1); }
  void insert(int x) { add(x, 1); }
  void erase(int x) { add(x, -1); }
};

BIT<int, N> bit;
int cnt[N];
int m;

void buildCnt() {
  for (int i = 1; i <= m; ++i) {
    cnt[i] = bit.get(i);
  }
}

struct SegmentTree {
  vector<int> tree;
  SegmentTree() : tree(3 * N, 0) {}
  void modify(int p, int value) {  // set value at position p
    for (tree[p += N] = value; p > 1; p >>= 1)
      tree[p >> 1] = max(tree[p], tree[p ^ 1]);
  }
  // r inclusive
  int query(int l, int r) {
    ++r;
    int res = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = max(res, tree[l++]);
      if (r & 1) res = max(res, tree[--r]);
    }
    return res;
  }
} seg_tree;

int lis_left[N];
int lis_right[N];

void buildLIS() {
  for (int i = m; i >= 1; --i) {
    lis_right[i] = 1 + seg_tree.query(0, cnt[i]);
    seg_tree.modify(cnt[i], lis_right[i]);
  }
  seg_tree = SegmentTree();
  for (int i = 1; i <= m; ++i) {
    lis_left[i] = 1 + seg_tree.query(0, cnt[i]);
    seg_tree.modify(cnt[i], lis_left[i]);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  int n;
  cin >> n >> m;
  while (n--) {
    int l, r;
    cin >> l >> r;
    bit.addRange(l, r);
  }
  buildCnt();
  buildLIS();

  int res = 0;
  for (int i = 1; i <= m; ++i) {
    res = max(res, lis_right[i] + lis_left[i] - 1);
  }
  cout << res << endl;

  return 0;
}