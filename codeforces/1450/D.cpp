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

const int N = 3e5 + 5;
vector<int> occ[N];
bool vis[N];
void init(int n) {
  for (int i = 1; i <= n; ++i) {
    occ[i].clear();
    vis[i] = false;
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

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    init(n);
    vector<int> v(n);
    cin >> v;
    int cnt_distinct = 0;
    for (int i = 0; i < n; ++i) {
      occ[v[i]].emplace_back(i);
      if (!vis[v[i]]) {
        vis[v[i]] = true;
        ++cnt_distinct;
      }
    }
    vector<bool> res(n);
    if (cnt_distinct == n) {
      res[0] = true;
    }
    if (vis[1]) {
      res.back() = true;
    }

    int l = 0, r = n - 1;
    for (int i = 1; i <= n; ++i) {
      auto& v = occ[i];
      if (sz(v) > 1) break;
      if (v.empty()) {
        ++r;
        break;
      }
      int x = v.back();
      if (x != l && x != r) break;
      if (x == l)
        ++l;
      else
        --r;
    }

    for (int i = 1; i < n - 1; ++i) {
      res[i] = (i >= r - l);
    }
    for (auto b : res) cout << b;
    cout << endl;
  }

  return 0;
}