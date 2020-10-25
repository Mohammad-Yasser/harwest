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

int n;

struct Op {
  bool add;
  int x;
};

vector<Op> ops;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  cin >> n;
  ops.resize(2 * n);
  vector<int> active_ops;
  for (int i = 0; i < 2 * n; ++i) {
    auto& op = ops[i];
    char c;
    cin >> c;
    op.add = (c == '+');
    if (!op.add) {
      cin >> op.x;
      if (active_ops.empty()) {
        cout << "NO" << endl;
        return 0;
      }
      ops[active_ops.back()].x = op.x;
      active_ops.pop_back();
    } else {
      active_ops.emplace_back(i);
    }
  }
  set<int> st;
  for (auto& op : ops) {
    if (op.add) {
      st.emplace(op.x);
    } else {
      if (*st.begin() != op.x) {
        cout << "NO" << endl;
        return 0;
      }
      st.erase(st.begin());
    }
  }

  cout << "YES" << endl;
  for (auto& op : ops) {
    if (op.add) {
      cout << op.x << " ";
    }
  }
  cout << endl;
  return 0;
}