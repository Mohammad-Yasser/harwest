#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int64_t inf = (int64_t) 1e17 + 42;

struct LiChaoMax {
  struct Line {
    Long a, b;
    Line() {
      a = 0;
      b = 0;
    }
    Line(Long _a, Long _b) {
      a = _a;
      b = _b;
    }
    Long eval(Long x) {
      return a * 1ll * x + (Long) b;
    }
  };

  struct Node {
    Node *l, *r;
    Line f;

    Node() {
      f = Line();
      l = nullptr;
      r = nullptr;
    }
    Node(Long a, Long b) {
      f = Line(a, b);
      l = nullptr;
      r = nullptr;
    }
    Node(Line v) {
      f = v;
      l = nullptr;
      r = nullptr;
    }
  };

  typedef Node* NodePointer;

  NodePointer root;
  int sz;
  void init(int _sz) {
    sz = _sz + 1;
    root = nullptr;
  }

  void addLine(Long a, Long b) {
    Line v = Line(a, b);
    insert(v, -sz, sz, root);
  }
  Long query(int x) {
    return query(x, -sz, sz, root);
  }

  void insert(Line &v, int l, int r, NodePointer &nd) {
    if (!nd) {
      nd = new Node(v);
      return;
    }

    int64_t trl = nd->f.eval(l), trr = nd->f.eval(r);
    int64_t vl = v.eval(l), vr = v.eval(r);

    if (trl >= vl && trr >= vr) return;
    if (trl < vl && trr < vr) {
      nd->f = v;
      return;
    }

    int mid = (l + r) >> 1;
    if (trl < vl) swap(nd->f, v);
    if (nd->f.eval(mid) > v.eval(mid))
      insert(v, mid + 1, r, nd->r);
    else
      swap(nd->f, v), insert(v, l, mid, nd->l);
  }

  Long query(int x, int l, int r, NodePointer &nd) {
    if (!nd) return -inf;
    if (l == r) return nd->f.eval(x);

    int mid = (l + r) >> 1;
    if (mid >= x) return max(nd->f.eval(x), query(x, l, mid, nd->l));
    return max(nd->f.eval(x), query(x, mid + 1, r, nd->r));
  }
} tree;

struct Rect {
  Long x, y, a;
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  vector<Rect> rects(n);

  for (auto& rect : rects) {
    cin >> rect.x >> rect.y >> rect.a;
  }

  sort(rects.begin(), rects.end(), [](const Rect& r1 , const Rect& r2) {
    return r1.x < r2.x;
  });

  tree.init(1e9 + 3);

  Long res = 0;

  tree.addLine(0, 0);

  for (auto& rect : rects) {
    Long tmp = tree.query(rect.y);
    tmp += rect.x * rect.y - rect.a;
    res = max(res, tmp);
    tree.addLine(-rect.x, tmp);
  }

  cout << res;

}
